## What Is a Program?

- A **program** is a set of **instructions** designed to **operate on data**.
- **No data = no meaning.** Instructions exist *to do something with* data.

  program = instructions + data
  ---

## What Is a Data Structure?

> A **data structure** is a specific **arrangement of data in memory** to make operations like searching, sorting, updating, or inserting efficient.

### Key Questions ❓ 

| Question | Answer |
|------------|-----------|
| **Where is it?** | In **main memory (RAM)** — not on disk. |
| **When does it exist?** | During **execution** — as part of a running program. |
| **Why use them?** | To manage data **efficiently** (time & space). |

---

## Runtime Memory Layout

> During execution, your program lives in **user space**, while the OS runs in **kernel space**. Here’s a simplified view of how memory is organized:

```
+----------------------------+
| Kernel Space (OS)         | ← Protected, privileged (syscalls, I/O, memory mgmt)
+----------------------------+
| User Space (Your Program) | ← Your code and data structures live here
|   +--------------------+  |
|   | Stack             |  | ← Function calls, local variables (LIFO)
|   | Heap              |  | ← Dynamically allocated memory (e.g., linked lists)
|   | Data Segment      |  | ← Global & static variables
|   | Text Segment      |  | ← Program code (compiled instructions)
|   +--------------------+  |
+----------------------------+
```

> **Kernel Space** is not directly accessible by your code — interaction happens through **system calls**.  
> **User Space** is where your program executes and manages its data using **data structures**.

> Your data structures (arrays, stacks, trees) usually live in **heap** or **stack**.

---

## Kernel vs User Space

| Term            | Description |
|-----------------|-------------|
| **Kernel Space** | Where the OS runs. Full control over hardware. User programs can only interact through system calls (like `read()`, `malloc()` indirectly). |
| **User Space**   | Where your **program and its data structures** live. Cannot directly touch hardware or kernel memory. |

- When your program allocates memory (e.g., `malloc()`), the **kernel handles** the underlying request.
- Your program lives in **user mode**, and the kernel guards against unsafe memory access.

---

## Data vs Databases vs Big Data

Let’s connect runtime memory to persistent storage and analytics:

| Concept       | Description |
|---------------|-------------|
| **Data Structure** | In-memory layout during program execution. Fast, temporary. |
| **Database (HDD/SSD)** | Persistent, structured storage. Slow, durable. |
| **Data Warehouse** | Centralized data collected from multiple sources. Used for analytics. |
| **Big Data** | Extremely large, often unstructured datasets analyzed using distributed computing. |

## Program Execution and Memory Use

```
[HDD] (Program, Files, DB)
   │
   └──▶ Loaded to [RAM] by OS
             │
             └──▶ Used by Program (Data Structures in Memory)
                        │
                        ▼
                Processed Data
                        │
                        ▼
          Stored in DB → Data Warehouse → Big Data Tools
```

> The flow of data during execution:
> - Starts from persistent disk storage (**HDD/SSD**)
> - Gets loaded into **RAM** by the **OS kernel**
> - Is processed via in-memory **data structures**
> - Results are stored back in **DBs**, or piped into **warehouses** and **Big Data pipelines**

---

## Key Takeaways

- ✅ Data structures live **only** in memory during execution (user space).
- ✅ They’re essential for **efficient program behavior**.
- ✅ Understanding memory layout and OS interaction helps you choose the right structure.
- ✅ Everything starts in RAM; disk data must be loaded before use.

---

## Static vs Dynamic Memory Allocation

> Understanding how memory is allocated in programs: what’s automatic, what’s manual, and where things live in RAM.

---

### Memory Basics

- Memory is **linear** — each byte has a **unique address**.
- Let's assume the system has **64 KB of RAM**.
- In larger systems, memory is often **divided into segments** to manage it more efficiently.

---

### Memory Segmentation

Memory is typically segmented into:

```
+-------------------------+
| Code Segment            | ← Contains compiled program instructions
+-------------------------+
| Stack Segment           | ← Holds local variables & function call info
+-------------------------+
| Heap Segment            | ← Dynamically allocated memory at runtime
+-------------------------+
```

- The program is originally stored on the **HDD**.
- When executed, the OS loads the **code** into the **Code Segment** of RAM.

---

### Static Memory Allocation

- Suppose `int` uses **2 bytes**, and `float` uses **4 bytes**.
- Declaring `int a; float b;` inside `main()` would allocate **6 bytes** on the **stack**.
- This allocation happens **during compile time** — it's called **static memory allocation**.
- The memory block created is called a **stack frame** or **activation record** of the `main()` function.

**No manual freeing is needed** — the system handles it when the function exits.

---

### Dynamic Memory Allocation (Heap)

- The **heap** is a memory area used when the program **needs memory at runtime**.
- Think of it like a **rentable storage unit**:  
  Use it → Access via pointers → Free it when done.

#### Important Points:

- Heap memory **must be accessed through a pointer**.
- Pointers themselves (e.g., `int *ptr`) are declared in the **stack**, inside the function’s stack frame.
- We allocate memory in the heap using functions like `malloc` in C.

```c
int *ptr = (int *)malloc(sizeof(int) * 5); // Allocates space for 5 integers
```

- The program can **only access** the heap memory via the pointer in the stack.
- When that memory is no longer needed, we must **free** it:

```c
free(ptr); // Releases heap memory
```

> ❗ If we forget to free it, we get a **memory leak**: unused memory that is still reserved and unavailable to others.

---

### ✅ Summary

| Allocation Type | Segment | Timing         | Manual Freeing? |
|------------------|---------|----------------|------------------|
| **Static**        | Stack   | Compile-time   | ❌ No             |
| **Dynamic**       | Heap    | Runtime        | ✅ Yes            |

> Good memory management = fast, efficient programs that don’t leak or crash.

## Physical Data Structures

> Structures that define **how memory is actually laid out** in RAM.

### Examples: `Array`, `Linked List`

---

### Why “Physical”?

Because these structures directly control **how memory is allocated**: whether contiguous or scattered.

---

### Array

- **Contiguous memory** allocation: elements sit **side by side** in memory.
- **Fixed size**: Must be known in advance.
- Can be created:
  - Inside the **stack**
  - Or in the **heap** (with a pointer to it in the stack)
- Efficient for **index-based access**.
  
> Best used when the size is known and won’t change frequently.

---

### Linked List 🔗 

- **Completely dynamic** in size.
- Made of **nodes**, where each node has:
  - A **data field**
  - A **link** (pointer) to the next node
- Nodes are allocated **in the heap**.
- The starting point (head pointer) is usually declared **in the stack**.

> Best for insertions, deletions, or growing/shrinking collections.

---

## Logical Data Structures

> Structures that define **how data is logically organized and accessed**: independent of memory layout.

### Examples: `Stack`, `Queue`, `Tree`, `Graph`, `Hash Table`

---

### Why “Logical”?

Because they are **abstract models**: the way we *think about* organizing data, not how memory is allocated.

- **Stack** → Last-In-First-Out (LIFO)
- **Queue** → First-In-First-Out (FIFO)
- **Tree** → Hierarchical relationships
- **Graph** → Nodes connected by edges
- **Hash Table** → Key-value mapping, often using arrays

> These logical structures are **implemented using physical structures** like arrays or linked lists.

---

### Summary
| Type         | Controls Memory? | Example Structures                  | Built On                     |
|--------------|------------------|--------------------------------------|-------------------------------|
| **Physical** | ✅               | Array, Linked List                   | Raw memory (stack/heap) built from memory       |
| **Logical**  | ❌               | Stack, Queue, Tree, Graph, Hash Table| Arrays, Linked Lists (Physical) built on top of physical structures |
> Bottom Line:  
> Logical structures are **concepts**,  
> Physical structures are the **bedrock of data structure implementations**.

> Array:
> - Built on a **contiguous block of RAM**
> - Memory is allocated either in the **stack** or **heap**
> - Accessed via **indexing** (constant time)

> Linked List
> - Built using **nodes** that contain:
  >     - **Data**
  >     - **Pointer** to the next node
>- Nodes are **dynamically allocated in the heap**
>- Accessed via **traversal** using pointers

---
## Abstract Data Types (ADT)

> A conceptual model for organizing data and defining valid operations — while **hiding internal details**.

---

### What Does “Abstract” Mean?

- “Abstract” means **you don’t see how something is implemented internally**.
- You only know:
  - What the data structure **does**
  - What operations are **allowed**
  - Not **how** those operations are performed at the binary or memory level

---

### What Is a Data Type?

A **data type** is a combination of:
- **Representations of data** (what it holds)
- **Operations on data** (what you can do with it)

> ✅ If we know **what the data holds** and **what can be done with it**,  
> we’ve defined a **data type**.

---

### Primitive vs Abstract Data Types

| Type                | Description                                | Example                |
|---------------------|--------------------------------------------|------------------------|
| **Primitive**        | Built-in by the language                   | `int`, `char`, `float` |
| **Abstract (ADT)**   | User-defined structure + allowed ops       | `Stack`, `Queue`, `List` |

> OOP revolutionized programming by enabling us to define **our own data types** (classes/objects)  
> and use them without needing to understand the internals.

---

### ADT = Interface, Not Implementation

You can think of an ADT like an **API**:

- You interact with it using well-defined methods:
  - `push()`, `pop()` for stack
  - `enqueue()`, `dequeue()` for queue
- You **don’t care** whether it’s implemented using an array or linked list.

---

### Summary

| Concept               | Describes                       |
|------------------------|---------------------------------|
| **Abstract**           | What it does, not how           |
| **Data Type**          | Data + Allowed Operations       |
| **ADT**                | Logical interface of a data type|
| **Implementation**     | Hidden, behind-the-scenes code  |

> The abstraction helps build **modular**, **reusable**, and **safe** code — just like using a car without needing to know how the engine works.
---
  