# Classes

- Group related data + functions together
- Members private by default (struct = public by default, same for inheritance)
- Struct → simple data holders, everything public, touch freely
- Class → has behavior + rules; private members so changes only go through methods
  The code can be written without the classes, but classes bring data adn functionalites plus the wall together!
- Same in the compiler, different in meaning: the keyword tells readers how to use it
- Example: StreamPeer `Camera` → class (status/resolution must go through methods)
- If the class has no member veraibles simply use the namespace to use the Function
- For member varaibles start with m\_

# Private and Public member varaibles

- Private memebr varaibles doesn't means "never changes". It means they need or can be able to changes through class internal rules. Rather than setting them outside like peer.id =2 or 3

# Static

- On a variable outside functions → only usable inside its own .cpp; other files can't reach it, even with extern
- Avoid global variables; if you really need one, make it static so it stays private to that .cpp

- Static member variable → one copy shared by all objects of the class

- Static member function → This function belongs to the class and no object is passed in and not needed to create an object to use this. Use this via the class!

# Constructors

- The constructor runs once when the object is created, so it's when you set up custom value before the object runs

- No return type & Name must match the name of the class and can be overloaded

# Destructor

- `~Peer()` runs automatically when the object dies (end of scope or explicit delete)
- Used for cleanup: free up resources, close connections and update counts, need to write or add to the destructor if you need more resources to clean up!

# Explicit

- Stops one-argument constructors from silently converting types

When the Argument expects Peer object and you send the string before compiler erros out it checks if there is conversion possible so it runs the constructor to see and it works out! But the implications for this is
you will have false number in the live count and etc!

Explicit will break the chain, explicit means the constructor only runs when you call it directly, like Peer(name) or Peer p{name}. But conversion of string to peer object when not called will not happen

- Object only created when written on purpose

# Stopped at Public and private memebrs adn access specifiers
