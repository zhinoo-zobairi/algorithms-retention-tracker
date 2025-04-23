#!/usr/bin/env python3
import os
import yaml
from pathlib import Path
import json
import re
from datetime import datetime


with open(os.environ["GH_EVENT_PATH"], "r") as f: # Now our script can read the issue title (event["issue"]["title"]) and act on it.
    event = json.load(f)

issue_title = event["issue"]["title"]

if not issue_title.lower().startswith("add:"):
    print("Not an algorithm addition issue.")
    exit(0)

algo_name = issue_title.split("Add:", 1)[1].strip()
if not algo_name:
    print("No algorithm name provided.")
    exit(1)

slug = algo_name.lower().replace(" ", "_")
metadata_path = Path(f"metadata/{slug}.yaml")
notes_dir = Path(f"algorithms/{slug}")
notes_file = notes_dir / "notes.md"
code_file = notes_dir / "code.py"

if metadata_path.exists():
    print(f"⚠️ Metadata already exists for {algo_name}")
    exit(0)

notes_dir.mkdir(parents=True, exist_ok=True)

notes_file.write_text(f"# {algo_name}\n\nAdd your notes here.")
safe_func_name = re.sub(r'\W|^(?=\d)', '_', slug)
code_file.write_text(f"# {algo_name} implementation\n\ndef {safe_func_name}():\n    pass\n")

metadata = {
    "algorithm": algo_name,
    "first_learned": datetime.now().strftime("%Y-%m-%d"),
    "notes_path": str(notes_file)
}

with metadata_path.open("w") as f:
    yaml.dump(metadata, f)

print(f"Metadata file created at {metadata_path} ✅")
print(f"Notes initialized at {notes_file}")

os.system("git config user.name 'github-actions'")
os.system("git config user.email 'github-actions@github.com'")
os.system(f"git add {metadata_path} {notes_file} {code_file}")
os.system(f"git commit -m 'Auto-generate metadata for {algo_name}'")
os.system("git push")