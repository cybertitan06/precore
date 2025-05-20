//Lets go over some type examples and how to change the assigned type of a variable.
//This exercise is for demonstration purposes only. You do not need to code anything.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	//int is one of the most often used types. It just means "integer"
	int x = 3;
	int y = 536;

	//if you want to work with decimal points, you'll need to declare a float
	float z = 1.24;
	float pi = 3.1415;

	//types matter a lot when you do math! so be careful when you work with multiple types.
	int sum1 = x + y;
       	int sum2 = z + pi; //whats going to happen here? we're assigning the sum of two floats to an int...
	float floatsum = z + pi;
	printf("our first sum is %d\n",sum1); //don't worry too much about formatting of the print statments here, we'll cover printf later on with strings.
	printf("our sum of floats is %d\n",sum2);
	printf("our corrected sum of floats is %f\n",floatsum);

	//note that once a variable has been declared, we don't need to include it's type when we reference it again later, even if we are reassigning it
	x = 10;
	y = 3;
	int quotient = x/y;
	float floatquotient = x/y; //now we're assigned an integer to a float, so we're going to lose precision again. the result will be an int, that will then get casted to a float.
	float castedquotient = (float) x/y; //if we cast one (or both) of the variables to a float, then the result will be a float.
	//the above two statements look very similar, but think of it as an order of operations problem. are you getting an answer, then changing its type? Or changing the type first, to get a better answer?
	printf("our int quotient is %d\n",quotient);
	printf("our float quotient is %f\n",floatquotient);
	printf("our casted quotient is %f\n",castedquotient);

	//now that we've talked about numbers with and without decimals. Lets talk about negative numbers.
	//Most numbers are signed by default. This means that part of their data includes whether they are positive or negative.
	//you can declare a number to be unsigned if you never intend to use the variable to hold a negative value.
	//the reason this matters is because, by losing the ability to make this number negative, we've gained back the bit that was used for its sign, and now we have room to store larger numbers.
	//Lets look at this more closely;
	
	int a = 0;
	unsigned int b = 0;
	a = a - 1;
	b = b - 1;
	printf("the value of a is: %d\n",a); 
	printf("the value of b is: %u\n",b);

	printf("the raw value of a is: %p\n",a); //these lines will generate compiler warnings. This is intentional
	printf("the raw value of b is: %p\n",b);


	//notice when we subtracted 1 from both a and b, we made them both negative one. That's fine for a because a is signed. But b is never supposed to be negative, because we declared it
	//as being unsigned. So instead, we caused what is called an "underflow". Imagine the odometer in your car. When it reaches 999999999 miles, it will keep turning and end up back at 000000000.
	//we just did the same thing, but in the other direction. notice that in the second print statment (what I refer to as the "raw value") the values of a and b are the same. The point here is that, while
	//the underlying 1s and 0s stored in a and b are the same, we told the program to interpret them differently.
	return 0;
}
