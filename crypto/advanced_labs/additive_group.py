import Exception

class GroupException(Exception):
    pass

class Group:
    def __init__(self, p, operation):
        if not isinstance(p, int):
            raise TypeError("p must be an int")
        self.p = p
        self.op = operation
        self.g = None
    
    def __init__(self, p, g, operation):
        if not isinstance(g, int):
            raise TypeError("g must be an int")
        if not isinstance(p, int):
            raise TypeError("p must be an int")
        self.p = p
        self.g = g
        self.op = operation

    def set_generator(self, g):
        if not isinstance(g, int):
            raise TypeError("g must be an int")
        self.g = g

    def get_generator(self):
        return self.g

    def diffie_hellman(self, priv, pub):
        if self.g is None:
            raise GroupException("The generator cannot be None.  Please set with Group.set_generator")