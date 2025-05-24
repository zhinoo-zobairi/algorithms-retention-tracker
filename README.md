# Algorithms Retention Tracker

Welcome to my personal algorithm learning repo, designed with long-term memory and spaced repetition in mind.

This isn't just about solving problems once, it's about **retaining them deeply**.

---

## What This Repo Does

This repository automates and tracks my algorithm learning using GitHub-native tools:

- Today you want to learn Merge Sort? Then Create a GitHub Issue like `Add: Merge Sort`
- GitHub Action automatically generates:
  - `metadata/merge_sort.yaml`
  - `algorithms/merge_sort/notes.md`
  - `algorithms/merge_sort/code.py`
- Spaced repetition reminders following .yaml creation will be sent on days:
  - **1**, **3**, **7**, **14**, **28**, **56**, **112**, **224**, **365** after learning
- Reminder shows up as a GitHub issue + email

---

## Why I Built This

I don’t want to forget what I learn.

This system is:
- Habit-forming
- Inspired by spaced repetition concept by Ebbinghaus
- Fully automated using GitHub Actions

---

## How To Use It

1. Open a new GitHub Issue with the title:
 - `Add: Your Algorithm Name`

2. The bot will:
- Generate all starter files and metadata
- Post a confirmation comment on the issue that your first reminder is due tomorrow

3. Each day, the system checks for review dates and sends a reminder if it’s:
- Day 1, 3, 7, or 14, 28, 56, 112, 224, 365 since the algorithm was added

---

## Repo Structure

```bash
metadata/
merge_sort.yaml     # Learning date & path to notes

algorithms/
merge_sort/
 notes.md          # Theory, dry runs, edge cases
 code.py           # Implementation
utils/
generate_metadata_from_issue.py
reminder_check.py

.github/workflows/
auto_metadata_from_issue.yml
review_reminder.yml

---

## Stay sharp. Stay consistent.

> "Learn deeply, not just quickly."
