#!/usr/bin/env python3
import os
import yaml
from pathlib import Path
import sys
import requests
from datetime import datetime, date

METADATA_DIR = Path("metadata")
ALGORITHMS_DIR = Path("algorithms")
TODAY = datetime.now().date()
REMINDER_DAYS = [1, 3, 7, 14]

try:
    REPO = os.environ["REPO"]
    GITHUB_TOKEN = os.environ["GITHUB_TOKEN"]
except KeyError as e:
    print(f"Required environment variable {e} not found!")
    sys.exit(1)

def parse_date(date_field):
    if isinstance(date_field, datetime):
        return date_field.date()
    elif isinstance(date_field, str):
        return datetime.strptime(date_field, "%Y-%m-%d").date()
    elif isinstance(date_field, date):
        return date_field
    else:
        raise ValueError(f"Unsupported date format: {date_field}")
    
def create_github_issue(title, body):
    """Create a GitHub issue using the REST API."""
    print(f"Creating issue: {title}")
    
    url = f"https://api.github.com/repos/{REPO}/issues"
    headers = {
        'Authorization': f'token {GITHUB_TOKEN}',
        'Accept': 'application/vnd.github.v3+json'
    }
    data = {
        'title': title,
        'body': body,
        'labels': ['review-reminder']
    }
    
    response = requests.post(url, headers=headers, json=data)
    if response.status_code == 201:
        print(f"Successfully created issue: {title} ✅")
        return True
    else:
        print(f"Failed to create issue. Status code: {response.status_code}")
        print(f"Response: {response.text}")
        return False

def create_review_file(algo_name, algo_dir, day_number):
    """Create a review file in the algorithm's directory."""
    algo_folder_name = algo_name.lower().replace(' ', '_')
    
    algo_path = ALGORITHMS_DIR / algo_folder_name
    if not algo_path.exists():
        print(f"⚠️ Algorithm directory for {algo_name} not found at {algo_path}")
        if algo_dir and Path(algo_dir).exists():
            algo_path = Path(algo_dir)
        else:
            print(f"Cannot create review file - directory not found")
            return False
    
    review_file = algo_path / f"review_day_{day_number}.py"
    
    if review_file.exists():
        print(f"Review file {review_file} already exists, skipping creation")
        return False
        
    # Generate content based on review day
    content = f"""# Review Day {day_number} for {algo_name}
# Created on {TODAY.strftime('%Y-%m-%d')}

'''
This is your review exercise for {algo_name}.
Complete the implementation below to reinforce your understanding.
'''

def {algo_name.lower().replace(' ', '_')}(items):
    \"\"\"
    Implementation of {algo_name}
    
    TODO: Implement the algorithm from memory to reinforce your learning
    \"\"\"
    # Your implementation here
    pass


# Test your implementation
if __name__ == "__main__":
    # Add test cases here
    test_data = [5, 2, 9, 1, 5, 6]
    result = {algo_name.lower().replace(' ', '_')}(test_data)
    print(f"Result: {{result}}")
"""

    # Write the file
    review_file.write_text(content)
    print(f"Created review file: {review_file} ✅")
    return True

def main():
    """Main function to check for algorithms needing review."""
    if not METADATA_DIR.exists() or not METADATA_DIR.is_dir():
        print(f"Metadata directory '{METADATA_DIR}' not found!")
        sys.exit(1)

    reminders_created = 0
    review_files_created = 0

    files = list(METADATA_DIR.glob("*.yaml")) + list(METADATA_DIR.glob("*.yml"))

    for file_path in files:
        try:
            print(f"Processing {file_path}")

            with file_path.open() as f:
                data = yaml.safe_load(f)

                algo = data.get("algorithm", data.get("name", "Unknown Algorithm"))

                if "first_learned" not in data:
                    print(f"⚠️ No 'first_learned' field in {file_path.name}")
                    continue

                learned_on = parse_date(data["first_learned"])
                days_since = (TODAY - learned_on).days

                notes_path = data.get("notes_path", "")
                algo_dir = data.get("algorithm_dir", "")
                base_url = f"https://github.com/{REPO}/blob/master"
                if notes_path:
                    notes_md = f"- [View your notes]({base_url}/{notes_path})" if notes_path else "*No notes path provided.*"
                else:
                    notes_md = "*No notes path provided.*"

                if days_since in REMINDER_DAYS:
                    review_file_created = create_review_file(algo, algo_dir, days_since)
                    if review_file_created:
                        review_files_created += 1
                    
                    review_file_link = ""
                    algo_folder_name = algo.lower().replace(' ', '_')
                    review_file_path = f"algorithms/{algo_folder_name}/review_day_{days_since}.py"
                    if Path(review_file_path).exists():
                        review_file_link = f"- [Complete today's review exercise]({base_url}/{review_file_path})" if Path(review_file_path).exists() else ""
                    
                    title = f"Review Reminder: {algo} (Day {days_since})"
                    body = f"""## Time to review {algo}!

It's been {days_since} days since you learned this algorithm.

**Spaced repetition** helps move knowledge to long-term memory.

### Review Material:
{notes_md}
{review_file_link}

*This reminder was automatically generated by your algorithm learning system.*
"""
                    if create_github_issue(title, body):
                        reminders_created += 1

        except Exception as e:
            print(f"Error processing file {file_path.name}: {str(e)}")

    print(f"Reminder check complete. Created {reminders_created} reminder issue(s) and {review_files_created} review file(s). ✅")

if __name__ == "__main__":
    main()