import builtins
print(len([item for item in dir(builtins) if callable(getattr(builtins, item))]))
