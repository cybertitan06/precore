# Make a class called Element with attributes Name, Symbol, Number
# Create an Element with class values 'Hydrogen', 'H', and 1
# For the Element class, define a method called dump() that prints the values of the object’s attributes


class Element():
    def __init__(self, name, symbol, number):
        self.name = name
        self.symbol = symbol
        self.number = number
    
    def dump(self):
        print(f"Name: {self.name}\nSymbol: {self.symbol}\nNumber: {self.number}")

element = Element('Hydrogen', 'H', 1)

element.dump()