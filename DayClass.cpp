// Blood Sugar Data class



class Data
{
private:
	float sum,
		sumOFCounter,
		max,
		min,
		count;

public:
	
	//Functions that add or increment variables recorded. addSum also calls maxCheck and minCheck.
	void addSum(float input);
	void maxCheck(float input);
	void minCheck(float input);
	//
	//Accessor Functions
	string returnSum(void);
	float returnMax(void);
	float returnMin(void);
	float returnCount(void);
};

void Day::inputNum(float input)
{
	addSum(input);
	maxCheck(input);
	minCheck(input);
}

void Data::addSum(float input)
{
	//check to see if valid, highest recorded blood sugar was 147.6 mmol/L
	if (input <= 150 && input > 0)
	{
		//checks to see if the daySum is going to overflow
		if (sum + input >= 1000000)
		{
			//Sets day sum to new number & increments the day sum counter
			sum = sum + input - 1000000;
			sumOFCounter++;
		}
		else
		{
			sum = sum + input;
		}
		count++;
		maxCheck(input);
		minCheck(input);
	}
}

void Data::maxCheck(float input)
{
	if (input > max)
	{
		max = input;
	}
}

void Data::minCheck(float input)
{
	if (input < min)
	{
		min = input;
	}
}

//Accessor Functions

string Data::returnSum()
{
	string sSum;
	if(sumOFCounter > 0)
	{
		sSum = to_string(sumOFCounter) + " x 1,000,000 + " + to_string(sum);
	}
	else
	{
		sSum = to_string(sum);
	}
	//find way of storing both the sum and sum overflow variables in string!	
	return sSum;
		
}

float Data::returnMax()
{
	return max;
}

float Data::returnMin()
{
	return min;
}

float Data::returnCount()
{
	return count;
}

//----------------------------------------------------
//Current idea of how to go on from here:
//
// Create another class called week, same functions etc.
// Create driver that handles input from user. When input needs entered the 
// input num function for both week and day is called to increment. 
// create array of days (size 14) and array of type week (size 2) to store data
// when N is called, it moves to the next day, and conditionally 
// (if day is 6th in the array) to the next week. 
//----------------------------------------------------
