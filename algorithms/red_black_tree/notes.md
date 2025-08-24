# Red-Black Tree

A Red-Black Tree is a height-balanced binary search tree with these core properties:
- Every node is either red or black.
- The root and all null (leaf) nodes are black.
- No two consecutive red nodes (parent and child) exist.
- Every path from root to leaf has the same number of black nodes (black-height).
- Newly inserted nodes are red by default.
- The tree height is bounded between log₂n and 2·log₂n.

## Insertion
- Insert the new node as red.
- If the new node is the root, recolor it to black.
- If the parent is black, no further action is needed.
- If the parent is red (red-red conflict):
    - **Case 1: Uncle is red**
        - Recolor parent and uncle to black, grandparent to red.
        - If grandparent is the root, recolor it to black.
        - Continue checking upward if needed.
    - **Case 2: Uncle is black or null**
        - Perform rotation around grandparent:
            - If the new node and parent are on the same side (LL or RR), do a single rotation (zig-zig).
            - If they are on opposite sides (LR or RL), do a double rotation (zig-zag).
        - After rotation, recolor: new parent takes the grandparent’s color; children become black.
- Always check the uncle’s color (including null, treated as black).

## Deletion
- Search for the node to delete.
- **If the node is red:**
    - Delete directly; successor (if any) takes its place.
    - No black-height change.
- **If the node is black:**
    - **If it has one red child:**
        - Replace node with its child and recolor the child to black.
    - **If it has two children:**
        - Swap values with in-order successor (or predecessor), then apply deletion logic at the successor’s original position.
    - **If it’s a leaf or has black child(ren):**
        - Must fix black-height:
        - **Case 1: Sibling is black with at least one red child**
            - Perform rotation so the red child moves up, preserving black-height.
            - If the far child (relative to parent) is black but the near child is red, double rotation is needed.
        - **Case 2: Sibling is red (its children must be black)**
            - Rotate sibling into parent’s position (LL or RR rotation), recolor.
            - Continue fix-up with the new black sibling.
        - **Case 3: Sibling is black with black children**
            - Recolor sibling to red.
            - If parent is black, repeat fix-up up the tree.
            - If parent is red, recolor parent to black (fix done).

## Diagnosing Insertion and Deletion in Red-Black Trees
> **Key Diagnostic:**
> - In insertion, always check the uncle.
> - In deletion, always check the sibling.

### Insertion: What to Check and Do
1. Is the new node the root?
    - Yes → Color it black.
    - No → Color it red.
2. Is the parent black?
    - Yes → Done.
    - No → Parent is red (red-red conflict):
        - Is the uncle red?
            - Yes → Recolor parent and uncle to black, grandparent to red.
            - If grandparent is root, recolor it to black.
            - Continue upward if needed.
            - No (uncle black or null):
                - Are new node and parent on same side?
                    - Yes (LL or RR) → Single rotation (zig-zig) at grandparent.
                    - No (LR or RL) → Double rotation (zig-zag) at grandparent.
                - Recolor after rotation: new parent gets grandparent’s color; children become black.

**Quick Rule:**
“Red parent? Check uncle!
If uncle is red, recolor; if uncle is black, rotate + recolor.”

### Deletion: What to Check and Do
1. Is the node to delete red?
    - Yes → Delete directly.
2. Is the node to delete black?
    - Yes → Must fix black-height.
        - Has single red child?
            - Replace and recolor child to black.
        - Otherwise:
            - Is sibling red?
                - Yes, with black children → Rotate sibling into parent’s place (LL or RR), recolor, continue with new black sibling.
                - Yes, with at least one red child → Perform rotation and recoloring so that the red child replaces the sibling, restoring black-height.
            - Is sibling black?
                - Both sibling’s children black → Recolor sibling red, adjust parent:
                    - If parent is black → Continue fix-up upward.
                    - If parent is red → Recolor parent black; done.
                - At least one sibling child red → Rotate (single or double) so red child moves up, recolor to restore black-height.

**Quick Rule:**
“Deleting red? Easy — just delete.
Deleting black? Check sibling:
Red sibling → rotate;
Black sibling with black kids → recolor;
Black sibling with red kid → rotate + recolor.”

---

**After Any Rotation: Diagnostic Checklist**
After every rotation, check invariants:
- Any consecutive reds?
- Black-heights equal on all paths?
- Is the root black?

If violated → recolor immediately.

---

Final note:
Red-Black Tree fix-ups are not just “rotate or recolor”; they are deliberate, invariant-driven repairs. 

Think like an engineer: rotations adjust shape, recolorings enforce rules.
