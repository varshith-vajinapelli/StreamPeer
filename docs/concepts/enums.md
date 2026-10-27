### Compound Types

Compound types are built from fundamental types and other types.

Some compound types we learned:

- Enums (scoped and unscoped)
- Class types (structs and classes)

### Enums

Enums are program-defined types used to represent a fixed set of related constants (choices).

Example: TrafficLight → red, yellow, green.

Since enums are program-defined types, they generally need to be fully defined before we use them.

### Unscoped Enums

- Used to group related choices, like Degree (CSE, CLA) or Major (CS, EE, ME).
- Enumerators are placed in the scope where the enum is defined.
- This can pollute the global scope, and we can't have two enumerators with the same name in that scope.
- Can implicitly convert to integers.

```cpp
enum Error {
    normal = 0,
    warning,
    info
};
```

**Naming convention:** Capitalize enum type names and use lowercase for enumerators.

### Scoped Enums (`enum class`)

Scoped enums solve some problems with unscoped enums.

Two main advantages:

- Enumerators stay inside the enum's own scope, so we access them using `::`.
- They don't implicitly convert to integers, giving better type safety.

```cpp
enum class Color {
    red,
    green,
    blue
};

Color shirt{Color::red};
```

**Remember:** Prefer `enum class` in most cases because it avoids naming conflicts and provides stronger type safety.
