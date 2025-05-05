#!/usr/bin/env python3
import os
import yaml
import base64
from pathlib import Path
import sys
import requests
from datetime import datetime, date

METADATA_DIR = Path("metadata")
ALGORITHMS_DIR = Path("algorithms")
TODAY = datetime.now().date()
REMINDER_DAYS = [1, 3, 7, 14, 28, 56, 112, 224, 365]

LANGUAGE_CONFIG = {
    1: {"extension": "c", "display_name": "C"},
    3: {"extension": "java", "display_name": "Java"},
    7: {"extension": "js", "display_name": "JavaScript"},
    14: {"extension": "py", "display_name": "Python"},
    28: {"extension": "c", "display_name": "C"},
    56: {"extension": "java", "display_name": "Java"},
    112: {"extension": "js", "display_name": "JavaScript"},
    224: {"extension": "c", "display_name": "C"},
    365: {"extension": "java", "display_name": "Java"}
}

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

def get_template_for_language(language, algo_name, slug, day_number, today_str):
    """Generate code template based on programming language."""

    templates = {
        "c": f"""/**
 * Review Day {day_number} for {algo_name}
 * Created on {today_str}
 *
 * This is your review exercise for {algo_name}.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of {algo_name}
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void {slug}(int items[], int size) {{
    /* Your implementation here */
}}

int main() {{
    int test_data[] = {{5, 2, 9, 1, 5, 6}};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    {slug}(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {{
        printf("%d ", test_data[i]);
    }}
    printf("\\n");
    
    return 0;
}}
""",
        "java": f"""/**
 * Review Day {day_number} for {algo_name}
 * Created on {today_str}
 *
 * This is your review exercise for {algo_name}.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class {slug.title().replace('_', '')} {{
    /**
     * Implementation of {algo_name}
     * TODO: Implement the algorithm from memory to reinforce your learning
     */
    public static void {slug}(int[] items) {{
        // Your implementation here
    }}
    
    public static void main(String[] args) {{
        int[] testData = {{5, 2, 9, 1, 5, 6}};
        {slug}(testData);
        System.out.println("Result: " + Arrays.toString(testData));
    }}
}}
""",
        "js": f"""/**
 * Review Day {day_number} for {algo_name}
 * Created on {today_str}
 *
 * This is your review exercise for {algo_name}.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of {algo_name}
 * @param {{Array}} items - The array to process
 * @returns {{Array}} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function {slug}(items) {{
    // Your implementation here
    return items;
}}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = {slug}(testData);
console.log(`Result: ${{result}}`);
""",
        "py": f"""# Review Day {day_number} for {algo_name}
# Created on {today_str}

'''
This is your review exercise for {algo_name}.
Complete the implementation below to reinforce your understanding.
'''

def {slug}(items):
    \"\"\"
    Implementation of {algo_name}
    
    TODO: Implement the algorithm from memory to reinforce your learning
    \"\"\"
    # Your implementation here
    pass

if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    result = {slug}(test_data)
    print(f"Result: {{result}}")
"""
    }
    
    return templates.get(language, templates["py"])  # Default to Python if language not found

def create_review_file(algo_name, algo_dir, day_number, language_config):
    """Create a review file in the algorithm's directory and commit it to GitHub."""
    algo_folder_name = algo_name.lower().replace(' ', '_')
    algo_path = ALGORITHMS_DIR / algo_folder_name

    # Get language configuration for this day
    extension = language_config["extension"]
    language_name = language_config["display_name"]
    
    # Check fallback directory or create one if needed
    if not algo_path.exists():
        print(f"⚠️ Default folder not found for {algo_name} at {algo_path}")
        if algo_dir and Path(algo_dir).exists():
            algo_path = Path(algo_dir)
            print(f"Using fallback directory: {algo_path}")
        else:
            # Create the directory if it doesn't exist
            algo_path.mkdir(parents=True, exist_ok=True)
            print(f"Created new directory: {algo_path}")

    # Build review file path
    review_file = algo_path / f"review_day_{day_number}.{extension}"
    if review_file.exists():
        print(f"⚠️ Review file already exists: {review_file}")
        print("🔍 Skipping creation and push.")
        return False

    # Generate review file content
    slug = algo_name.lower().replace(' ', '_')
    # Get today's date
    today_str = TODAY.strftime('%Y-%m-%d')
    content = get_template_for_language(extension, algo_name, slug, day_number, today_str)
    # Write the file
    review_file.write_text(content)
    print(f"Created {language_name} review file: {review_file}")

    # Commit and push with error checking
    commands = [
        "git config user.name 'github-actions'",
        "git config user.email 'github-actions@github.com'",
        f"git add {review_file}",
        f"git commit -m 'Add {language_name} review file for {algo_name} (Day {day_number})'",
        "git push"
    ]
    
    for cmd in commands:
        print(f"Executing: {cmd}")
        result = os.system(cmd)
        if result != 0:
            print(f"Command failed: {cmd} (exit code: {result})")
            return False
    
    print("Git operations completed successfully")
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
                    # Get the language for this reminder day
                    language_config = LANGUAGE_CONFIG.get(days_since, {"extension": "py", "display_name": "Python"})
                    extension = language_config["extension"]
                    language_name = language_config["display_name"]
                    
                    review_file_created = create_review_file(algo, algo_dir, days_since, language_config)
                    if review_file_created:
                        review_files_created += 1
                    
                    review_file_link = ""
                    algo_folder_name = algo.lower().replace(' ', '_')
                    review_file_path = f"algorithms/{algo_folder_name}/review_day_{days_since}.{extension}"
                    
                    if Path(review_file_path).exists():
                        review_file_link = f"- [Complete today's {language_name} review exercise]({base_url}/{review_file_path})"
                    
                    title = f"Review Reminder: {algo} (Day {days_since} - {language_name})"
                    body = f"""## Time to review {algo} in {language_name}!

It's been {days_since} days since you learned this algorithm. Today's review is in **{language_name}**.

**Spaced repetition** helps move knowledge to long-term memory. Implementing the same algorithm in different languages reinforces your understanding of the core concepts.

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