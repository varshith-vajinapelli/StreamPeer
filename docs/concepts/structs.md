## Classes and Structs

- Both `class` and `struct` are almost identical in C++.
- Both usually need objects to access non-static members. `static` members can be accessed directly using the class name.
- `class` → Private by default.
- `struct` → Public by default.
- One reason for having structs in C++ is compatibility with C.

### Private and Public

- `private` → Outside code cannot directly access these members. Only the class's own members and friends can access them.
- `public` → Outside code can directly access these members.

The main point is **encapsulation**. We don't want other developers to directly change internal variables and bypass the rules we created.

Example: `account.balance = 500000;` should not be allowed if `balance` is private.

### When to use Struct vs. Class?

- **Struct:** Simply group related data together under one name, usually with public members.
- **Class:** When an object needs to manage its own data, enforce rules, and hide internal implementation details.

### Structs

```cpp
struct Employee {
    int id{};
    int age{18};
    double wage{};
};
```

- `id`, `age`, and `wage` are called **member variables**.
- Prefer `{}` initialization instead of leaving variables uninitialized.
- `int age{18};` → Default value is 18.
- Explicit values override default values.

### Aggregate Initialization

Initializing members directly using `{}` without needing a user-defined constructor.

```cpp
Employee e1{101, 21, 15.75};
```

- Values follow the order members are declared.
- If a value is not provided, its default is used.
- A struct with private non-static data members is not an aggregate.

### Passing and Returning Structs

Structs are useful when we have multiple related variables to pass to a function.

Instead of passing everything individually, group them into a struct and pass that.

We've already seen this pattern in C system calls like `sigaction()` and `stat()`.

```cpp
void printEmployee(const Employee& employee);
```

- `Employee e` → Pass by value (copy).
- `Employee& e` → Pass by reference (can modify original).
- `const Employee& e` → Pass by reference without copying; cannot modify through the reference.
- `Employee createEmployee()` → Return an Employee by value.

### Understanding const

Read simple declarations from right to left.

```cpp
const Employee& employee;
```

`employee` is a reference to a const Employee.

This means we cannot modify the underlying Employee through this reference.

```cpp
const Employee* ptr; // Pointer to const Employee
Employee* const ptr = &e1; // Const pointer to Employee
```

- `const Employee*` → Cannot modify the Employee through the pointer, but can change where the pointer points.
- `Employee* const` → Cannot change where the pointer points, but can modify the Employee.

### Member Selection Operators

Used to access members of a struct or class.

```cpp
Employee joe{101, 21, 15.75};

Employee* ptr{&joe};
Employee& ref{joe};
```

- `joe.age` → Access member through object.
- `ref.age` → Access member through reference.
- `ptr->age` → Access member through pointer.
- `(*ptr).age` → Same as `ptr->age`.

**Remember:** `.` for objects/references and `->` for pointers.
