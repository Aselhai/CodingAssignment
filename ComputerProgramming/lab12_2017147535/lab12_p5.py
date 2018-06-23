import copy

class Fraction(object):

    # Special Methods
    def __init__(self, numerator, denominator):
        """Inits Fraction with values numerator and denominator."""

        self.__numerator = numerator
        self.__denominator = denominator
        self.reduce()

    def __repr__(self):
        """Returns Fraction value as x/y."""

        return str(self.__numerator) + '/' + str(self.__denominator)
    
    # Getter and Setter Methods
    def getNumerator(self):
        """Returns the numerator of a Fraction."""

        return self.__numerator

    def getDenominator(self):
        """Returns the demoninator of a Fraction."""

        return self.__denominator

    def setNumerator(self, value):
        """Sets the numerator of a Fraction to the provided value."""

        self.__numerator = value

    def setDenominator(self, value):
        """Sets the denominator of a Fraction to the provided value.

            Raises a ValueError exception if a value of zero provided.
        """

        if value == 0:
            raise ValueError('Divide by Zero Error')
        self.__denominator = value

    def copy(self):
        """Creates a copy of a given Fraction."""
        
        return copy.copy(self)

    def reduce(self):
        """Reduces self to simplest terms. Also removes the signs
        if both numerator and denominator are negative."""
        a = self.__numerator
        b = self.__denominator
 
        if a == 1:
            pass
        else:
            while b % a  != 0:
                c = b % a
                b = a
                a = c
            
            self.setNumerator(int(self.__numerator / a))
            self.setDenominator(int(self.__denominator / a))
        
    def adjust(self, factor):
        """Multiplies numerator and denominator by factor."""

        self.setNumerator(int(self.__numerator * factor))
        self.setDenominator(int(self.__denominator * factor))             
