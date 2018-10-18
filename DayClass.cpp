// Blood Sugar Data class

class Day
{
private:
	float daySum,
		daySumOFCounter,
		dayMax,
		dayMin,
		dayCount,
		weekSum,
		weekOFCounter,
		weekMax,
		weekMin,
		weekCount;

public:
	//inputNum is used when a number is added, and calls other
	//functions as appropriate
	void inputNum(float input);
	//
	//Functions that add or increment variables recorded for the day
	void addDaySum(float input);
	void dayMaxCheck(float input);
	void dayMinCheck(float input);
	void incDayCount(void);
	//
	//Functions that add or increment variables recorded for the week
};

void Day::inputNum(float input)
{
	addDaySum(input);
	dayMaxCheck(input);
	dayMinCheck(input);
}
void Day::addDaySum(float input)
{
	//check to see if valid, highest recorded blood sugar was 147.6 mmol/L
	if (input <= 150)
	{
		//checks to see if the daySum is going to overflow
		if (daySum + input >= 1000000)
		{
			//Sets day sum to new number & increments the day sum counter
			daySum = daySum + input - 1000000;
			daySumOFCounter++;
		}

	}
}

void Day::dayMaxCheck(float input)
{
	if (input > dayMax)
	{
		dayMax = input;
	}
}

void Day::dayMinCheck(float input)
{
	if (input < dayMin)
	{
		dayMin = input;
	}
}

void Day::incDayCount()
{
	dayCount++;
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