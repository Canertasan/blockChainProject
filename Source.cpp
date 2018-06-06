#include <string>
#include <iostream>
#include <fstream>
using namespace std;


//ÝNPUTNODE ********************************************************************************
struct inputNode {// input node !
	int transactionId;
	int outputLocation;
	inputNode* nextI;
	inputNode(int &_transactionId, int &_outputLocation, inputNode* _nextI)//constructor
	{
		transactionId = _transactionId;
		outputLocation = _outputLocation;
		nextI = _nextI;
	}
};

class linkedlistI// input linkedlist
{
private:
	inputNode *headI;		//Head transactionNode, start of LinkedList
public:
	linkedlistI();			//Constructor
	inputNode* headTaker();
	void printListI(inputNode* &headI);		//Prints the given LinkedList from head to end
	void addToBeginningI(int &transactionId, int &outputLocation);	//Inserts new transactionNode at the beginning of the LinkedList with given data
};


linkedlistI::linkedlistI()// default constructor
{
	headI = nullptr;
}

void linkedlistI::printListI(inputNode* &headI)//printLÝst func. I used that in printLÝstT();
{
	inputNode *tempI = headI;
	while (tempI != NULL)
	{
		cout << "Tid:" << tempI->transactionId << " Location:" << tempI->outputLocation << endl;
		tempI = tempI->nextI;
	}

	//	tempT = tempT->next;//= (*tempT).next;
}

inputNode* linkedlistI::headTaker()//head returner!
{
	return headI;
}


void linkedlistI::addToBeginningI(int &transactionId, int &outputLocation)// gathering information and adding the transactionNode!
{
	//List is empty
	if (headI == nullptr)
	{
		inputNode *ptr = new inputNode(transactionId, outputLocation, nullptr);// this is null bcs head is not exist!
		headI = ptr;
		headI->nextI = nullptr;
	}
	else// if it is not empty
	{
		inputNode *ptr = new inputNode(transactionId, outputLocation, headI);
		headI = ptr;
	}
	headTaker();// this return the header after all adding info
}

//ÝNPUTNODE ********************************************************************************

//outputNODE ***************************************************************
struct outputNode {// output node struct
	int amount;
	string sendTo;
	outputNode* nextO;

	outputNode(int &_amount, string &_sendTo, outputNode* _nextO)// our constructor (output)
	{
		amount = _amount;
		sendTo = _sendTo;
		nextO = _nextO;
	}
};


class linkedlistO
{
private:
	outputNode *headO;		//Head transactionNode, start of LinkedList
public:
	linkedlistO();			//Constructor
	outputNode* headTaker();
	void printListO(outputNode* &headO);		//Prints the given LinkedList from head to end
	void addToEndO(int &amount, string &sendTo);//Inserts new transactionNode at the beginning of the LinkedList with given data
};

linkedlistO::linkedlistO()// default constructor
{
	headO = nullptr;
}


void linkedlistO::printListO(outputNode* &headO)// print the whole linkedlist !
{
	outputNode *tempO = headO;
	while (tempO != NULL)
	{
		cout << "Amount:" << tempO->amount << " send to:" << tempO->sendTo << endl;
		tempO = tempO->nextO;
	}
	//	tempT = tempT->next;//= (*tempT).next;
}

outputNode* linkedlistO::headTaker()//head return function.
{
	return headO;
}


void linkedlistO::addToEndO(int  &amount, string &sendTo)// adding some info
{  /*
	//List is empty
	if (headO == nullptr)
	{
		outputNode *ptr = new outputNode(amount, sendTo, nullptr);
		headO = ptr;
		headO->nextO = nullptr;
	}
	else// list is not empty
	{
		outputNode *ptr = new outputNode(amount, sendTo, headO);
		headO = ptr;
	}
	headTaker();// this return the header after all adding info
	*/

	outputNode *ptr = headO;
	outputNode *temp = new outputNode(amount, sendTo, nullptr);
	//List is empty
	if (headO == nullptr)// this is for when the headT is empty So it is first node creator!
	{
		headO = temp;
	}
	else
	{
		while (ptr->nextO != nullptr)// and we keep adding node after first one !
		{
			ptr = ptr->nextO;
		}
		ptr->nextO = temp;
	}
	headTaker();// this is for give value for our essential header node

}


//outputNODE ***************************************************************

//TRANSACTÝON *******************************
struct transactionNode //transaction node struct!
{
	int tid;
	string owner;
	int PoW;
	int hval;
	transactionNode* nextT;
	inputNode* inputList;
	outputNode* outputList;

	transactionNode(int &_tid, transactionNode * _nextT, string &_owner, int &_PoW, int &_hval, inputNode* _inputList, outputNode* _outputList)// our constructor
	{
		tid = _tid;
		nextT = _nextT;
		owner = _owner;
		PoW = _PoW;
		hval = _hval;
		inputList = _inputList;
		outputList = _outputList;
	}
};

class linkedlistT // linkedlist T class 
{
private:
	transactionNode *headT;		//Head transactionNode, start of LinkedList
public:
	linkedlistT();			//Constructor
	transactionNode* headTaker();
	int hvalReturn();
	int PoWReturn();
	int tidReturn();
	void printListT(inputNode* &inputList, outputNode* &outputList);		//Prints the given LinkedList from head to end
	void addToEndT(int &tid, string &owner, int &PoW, int &hval, inputNode* &inputList, outputNode* &outputList, transactionNode* &bc);	//Inserts new transactionNode at the beginning of the LinkedList with given data
};

//Trying to create empty linkedlist.
linkedlistT::linkedlistT()
{
	headT = nullptr;
}




//TODO: implement the following function 
//If the list is empty print  "List is empty"
//Otherwise print each transactionNode's content to a different line
void linkedlistT::printListT(inputNode* &inputList, outputNode* &outputList)// print info!
{
	linkedlistI LLI;// this is provide their classes functions!
	linkedlistO LLO;// this is provide their classes functions!
	transactionNode *ptr = headT;
	while (ptr) { // when ptr is not equal to null
		if (ptr->tid > 1)  // this is for transactionode which has input info
		{
			cout << "Transaction id:" << ptr->tid << " owner:" << ptr->owner << " hash:" << ptr->hval << " PoW:" << ptr->PoW << endl << "Input List" << endl;//giving cout info
			LLI.printListI(ptr->inputList);// gathering whole list 
			cout << "Output List" << endl;
			LLO.printListO(ptr->outputList);// gathering whole list 
			// yo give cout of Transaction node. without output and input information.
			cout << endl;
		}
		else// this is for transactionode which hasnt input info
		{
			cout << "Transaction id:" << ptr->tid << " owner:" << ptr->owner << " hash:" << ptr->hval << " PoW:" << ptr->PoW << endl << "Input List" << endl;
			cout << endl;
			cout << "Output List" << endl;
			LLO.printListO(ptr->outputList);// yo give cout of Transaction node. without output and input information.
			cout << endl;
		}
		ptr = ptr->nextT;
	}
	//	tempT = tempT->next;//= (*tempT).next;
}

transactionNode* linkedlistT::headTaker()//return header.! I dont need that for now. Lets see
{
	return headT;
}


int mine(transactionNode *newT, transactionNode* bchain, int& hval, int& PoW, int threshold); // this is your CODE 
int tid = 1;
void linkedlistT::addToEndT(int &tid, string &owner, int &PoW, int &hval, inputNode* &inputList, outputNode* &outputList, transactionNode* &bc)// adding node !
{
	transactionNode *ptr = headT;
	transactionNode *temp = new transactionNode(tid, nullptr, owner, PoW, hval, inputList, outputList);
	//List is empty
	if (headT == nullptr)// this is for when the headT is empty So it is first node creator!
	{
		headT = temp;
	}
	else
	{
		while (ptr->nextT != nullptr)// and we keep adding node after first one !
		{
			ptr = ptr->nextT;
		}
		ptr->nextT = temp;
		mine(temp, bc, hval, PoW, 10);
		temp->hval = hval;
		temp->PoW = PoW;
	}
	bc = headT;// this is for give value for our essential header node!
}


	//TRANSACTÝON *****************************************
	//************************************************************YOUR CODE****************************************\\

int hashfun(transactionNode *newT, int prev_hval, int PoW) {
	int hval = (prev_hval + 1111) * (PoW + 1111);
	outputNode * outPtr = newT->outputList;
	while (outPtr) {
		hval += outPtr->amount;
		string str = outPtr->sendTo;
		for (int i = 0; i < str.length(); i++) {
			hval += ((int)str[i]);
		}
		outPtr = outPtr->nextO;
	}
	inputNode * inPtr = newT->inputList;
	while (inPtr) {
		hval += inPtr->transactionId;
		hval += inPtr->outputLocation;
		inPtr = inPtr->nextI;
	}
	return (hval % 137);
}
int mine(transactionNode *newT, transactionNode* bchain, int& hval, int& PoW, int
	threshold) {
	transactionNode* tmp = bchain;
	int prev_hval = 0;
	while (tmp) {
		prev_hval = tmp->hval;
		tmp = tmp->nextT;
	}

	PoW = 1;
	while ((hval = hashfun(newT, prev_hval, PoW)) >= threshold) {


		PoW++;
	}
	return PoW;
}
//************************************************************YOUR CODE ******************************************\\

linkedlistT LLT; // i define global bcs we need to use what ever i want about that class (usually for functions)

void printBlockchain(transactionNode *blockchain)// this is our blockchain printer!
{
	transactionNode* temp = blockchain;
	LLT.printListT(blockchain->inputList, blockchain->outputList);// this is use printListT and printListT use	printListI and printListO.	
}

void printRemainingMoney(transactionNode* blockchain, string user)
{
	bool finded = true;
	int totalAmount=0;
	cout << "Write the name you want to search: " << endl;
	cin >> user;

	transactionNode* ptr = blockchain;
	while (ptr != NULL)
	{
		if (ptr->owner != user)
		{
			while (ptr->outputList!= NULL && finded)
			{
				if (ptr->outputList->sendTo == user )
				{
					totalAmount += ptr->outputList->amount;
					finded = false;
				}
				ptr->outputList = ptr->outputList->nextO;
			}
			finded = true;
		}
		else
		{
			while (ptr->outputList != NULL && finded)
			{
				while (ptr->outputList->nextO!= NULL )
				{
					if (ptr->outputList->sendTo == user)
					{
						
					}
					else 
					{
						totalAmount -= ptr->outputList->amount;
						finded = false;
					}
					ptr->outputList = ptr->outputList->nextO;
				}
				ptr->outputList = ptr->outputList->nextO;
			}
			finded = true;
		}
		
		ptr = ptr->nextT;
	}

	cout << user<<"'s wallet: " << totalAmount << endl;
	
}

bool hasDuplicate(transactionNode* blockchain, bool &secondUse)
{
	transactionNode* ptr = blockchain->nextT;
	transactionNode* ptrI = blockchain->nextT->nextT;
	while (ptr != NULL&& ptrI != ptr)
	{
		while (ptrI != NULL )
		{
			if (ptrI->inputList == ptr->inputList)
			{
				secondUse = true;
			}
			ptrI = ptrI->nextT;
		}
		ptrI = ptr->nextT;
		/*
		if (ptr->nextT->inputList == ptr->inputList)
		{
			secondUse = true;
		}
		else if (ptr->nextT->nextT->inputList != NULL &&ptr->nextT->nextT->inputList == ptr->inputList)
		{
			secondUse = true;
		}
		ptr = ptr->nextT;
		*/
		ptr = ptr->nextT;
	}
	return secondUse;
}


void addTransaction(transactionNode* &blockchain)// add transaction func!!
{
	transactionNode *ptr = blockchain;
	bool ownerTrue = false, amountTrue = false, secondUse = false;
	tid++;
	int PoW = blockchain->PoW;
	int hval = blockchain->hval;
	int restAmount = 0, totalSendedAmount = 0, totalOwnerMoney = 0, counter = 1;
	linkedlistI LLI;
	linkedlistO LLO;
	int transactionid, outputLocation, amount;
	string owner, sendTo;
	cout << "Input the owner of the transaction: " << endl;
	cin >> owner;
	cout << "Write the input list in form of " << endl;
	cout << "'transactionId_1 outLocation_1 transactionId_2 outLocation_2 #'" << endl;
	cout << "put # after all the inputs finish : " << endl;
	while (cin >> transactionid)// this is for inputs
	{
		cin >> outputLocation;
		LLI.addToBeginningI(transactionid, outputLocation);// to collect our input.
		while (ptr->nextT != nullptr&&ptr->nextT->inputList != NULL)// and we keep adding node after first one !
		{
			if (ptr->nextT->inputList->transactionId == transactionid)
			{
				break;
			}
			else
			{
				ptr = ptr->nextT;
			}
		}
		while (ptr->outputList->nextO != nullptr&&counter != outputLocation)// and we keep adding node after first one !
		{
			ptr->outputList = ptr->outputList->nextO;
			counter++;
		}
		totalOwnerMoney += ptr->outputList->amount;
		if (ptr->outputList->sendTo != owner)
		{
			ownerTrue = true;
		}

	}
	cout << "Write the output list in form of " << endl;
	cout << "'amount_1 sentTo_1 amount_2 sentTo_2 #' " << endl;
	cout << "put # after all the inputs finish: " << endl;
	cin.clear();//clean the cin bool
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//clean the cin bool
	while (cin >> amount)// this is for output info
	{
		cin >> sendTo;
		LLO.addToEndO(amount, sendTo);// to collect our output.
		totalSendedAmount += amount;
	}
	if (totalOwnerMoney < totalSendedAmount)
	{
		amountTrue = true;
	}
	restAmount = totalOwnerMoney - totalSendedAmount;
	LLO.addToEndO(restAmount, owner);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');// to get cin again
	inputNode* inputList = LLI.headTaker();// to take inputList headI
	outputNode* outputList = LLO.headTaker();// to take outputList headO
	LLT.addToEndT(tid, owner, PoW, hval, inputList, outputList, blockchain);// eventually we use addToEndT func to gather all information in one struct!
	if (hasDuplicate(blockchain, secondUse))
	{
		cout << "Invalid T : Double spending!" << endl;
	}
	else if (ownerTrue)// VALÝDÝTY
	{
		cout << "Invalid T: input owner is not right!" << endl;
	}
	else if (amountTrue)
	{
		cout << "Invalid T: total output > total input! " << endl;
	}
	else// if conditions are okay
	{
		cout << "Hash: " << hval << " - PoW: " << PoW << endl;
		cout << "New transaction added successfuly! " << endl;
	}
}

int main()
{
	linkedlistI LLI;
	linkedlistO LLO;
	transactionNode* blockchain = nullptr;
	int hval, PoW, sendedMoney;
	string owner, word, sendTo;
	ifstream reader;//this is our reader
	reader.open("input.txt");//open the file 
	reader >> owner;//Take the owner
	reader >> hval;//take hashvalue
	reader >> PoW;//the the PoW value
	while (reader >> sendedMoney)// first we read one input.txt
	{
		reader >> sendTo;
		LLO.addToEndO(sendedMoney, sendTo);// this is for output info
	}
	inputNode* inputList = LLI.headTaker();// taking header
	outputNode* outputList = LLO.headTaker();// taking header
	LLT.addToEndT(tid, owner, PoW, hval, inputList, outputList, blockchain);// using there!!!

	//**********************************************************YOUR CODE**************************************************\\

	while (true)
	{
		cout << endl;
		cout << "******************************************************" << endl
			<< "***** 0 - EXIT PROGRAM ****" << endl
			<< "***** 1 – PRINT BLOCKCHAIN ****" << endl
			<< "***** 2 - PRINT REMAINING MONEY OF A USER ****" << endl
			<< "***** 3 - ADD A TRANSACTION ****" << endl
			<< "****************************************************" << endl;
		cout << endl;
		int option;
		cout << "Pick an option from above (int number from 0 to 3): ";
		cin >> option;
		switch (option)
		{
		case 0:
			cout << "PROGRAM EXITING ... " << endl;
			system("pause");
			exit(0);
		case 1:
			printBlockchain(blockchain);
			break;
		case 2:
			printRemainingMoney(blockchain, owner);
			break;
		case 3:
			addTransaction(blockchain);
			break;
		default:
			cout << "INVALID OPTION!!! Try again" << endl;
		}//switch
	}//while (true)

	 //******************************************************************YOUR CODE *************************************\\

	cin.get();
	cin.ignore();
	return 0;
}