#include <fstream>
#include <iostream>
using namespace std;

void printAry(ofstream& outFile, int charCount[]){
	int index = 0;// step 1: index <--0
	char symbol;
	while(index < 256){
		if(charCount[index]>0){// step 2: if charCounts[index] > 0
			symbol = (char)index;//symbol <-- cast index to charactor
			outFile<<symbol<<" "<<charCount[index]<<endl;//write symbol  charCounts[index]  per text line
		}// step 4: repeat step 2 to step 3 while i < 256
		index++;// step 3: index ++
	}
}


int main(int argc, char const *argv[]){

	if(argc<2){
		cout<<"Too few arguments.";
		exit(1);
	}

	// 	step 0: - open input and output files
	ifstream inFile;
	inFile.open(argv[1]);
	ofstream outFile;
	outFile.open(argv[2]);
	int charCount[256] = {0};// - initialize charCounts array to zero.
	char charIn;
	int index;

	
	while(inFile.get(charIn)){//step 1: charIn <- get the next character from inFile, 
		index = (int)charIn;//step 2: index <- cast charIn to integer
	    if(index != 10)//dont increment space and newline and carriage returns
	    	charCount[index]++; // step 3: charCounts[index]++
	}// step 4: repeat step 1 to step 3 while infile is not empty
	printAry(outFile, charCount);// step 5: printAry
	inFile.close();// step 6:
	outFile.close();//close all files

	return 0;
}

// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// void printAry(ofstream& outFile, int charCounts[]) {
//     //--------------------------
//     //  Step 1: index <--0
//     //--------------------------
//     int index = 0;
//     char symbol;

//     while (index < 256) {
//         //--------------------------
//         //  Step 2: if charCounts[index] > 0
//         //              symbol <-- cast index to character
//         //              write symbol  charCounts[index]  per text line
//         //--------------------------
//         if (charCounts[index] > 0) {
//             symbol = (char) index;
//            // if (index > 127) cout << symbol << " " << index << " ";
//             cout<< index<<" " << symbol << " " << charCounts[index] << endl;
//             outFile << symbol << " " << charCounts[index] << endl;
//         }
//         //--------------------------
//         //  Step 3: index ++
//         //--------------------------
//         index++;
//     }
//     //--------------------------
//     //  Step 4: repeat step 2 to step 3 while i < 256
//     //--------------------------
// }

// int main(int argc, char* argv[]) {
//     //--------------------------
//     //  Step 0: - open input and output files
//     //	        - initialize charCounts array to zero.
//     //--------------------------
//     ifstream inFile;
//     ofstream outFile;

//     int charCounts[256];

//     if (argc > 1) {

//         inFile.open( argv[1] );
//         outFile.open( argv[2] );

//         if (argc < 3) {
//             cout << "Please enter a file name to write output.\n Ex: output.txt\n";
//             return -1;
//         }

//         if (inFile.is_open() && inFile.good()) {
//             //--------------------------
//             //  Step 1: charIn <- get the next character from inFile, one character at a time
//             //--------------------------
//             char charIn;
//             int index;

//             while (!inFile.eof()) {

//                 inFile.get(charIn);
//                 // cout << charIn << endl;

//                 //  If statement accounts for empty space, new line, and carriage return
//                 // if (charIn == '\n' || charIn == '\r') { continue; }

//                 //--------------------------
//                 //  Step 2: index <- cast charIn to integer
//                 //--------------------------
//                 index = (int) charIn;
//                 //--------------------------
//                 //  Step 3: charCounts[index]++
//                 //--------------------------
//                 if ( index != 10 && index != 13)
//                     charCounts[index]++;
//             }
//             //--------------------------
//             //  Step 4: repeat step 1 to step 3 while infile is not empty
//             //--------------------------
//             //--------------------------
//             //  Step 5: printAry // see algorithm below
//             //--------------------------
//             printAry(outFile, charCounts);

//         } else {
//             cout << "Failed to open file: \"" << argv[1] << "\"\n Exiting...\n";
//         }

//     } else {
//         cout << "No file name entered, please enter a file name. \n Exiting...\n";
//         return -1;
//     }
//     //--------------------------
//     //  Step 6: close all files
//     //--------------------------
//     inFile.close();
//     outFile.close();

//     return 0;
// }