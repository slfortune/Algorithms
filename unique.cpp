/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Sophie Fortunato
 * Date        : 2/5/2022
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

/*
* Checks to see if all characters
* in string s are lowercase.
* True if all lowercase, false otherwise.
*/

bool is_all_lowercase(const string &s) 
{
    if(s.empty() == false)
    {
        for(unsigned int i = 0; i<s.length(); i++)
        {
            // find_first_not_of was learned from google :)
            if (s.find_first_not_of("abcdefghijklmnopqrstuvwxyz") !=
                std::string::npos)
            {
                 return false;
            }

            if(islower(s[i]))
            {
                return true;
            }
            
        }
    }

    return false;

}

/*
* Returns true if no duplicate letters are found in the string;
* returns false otherwise.
* Only uses a single int for storage and
* bitwise/bitshift operators.
*/

bool all_unique_letters(const string &s) 
{
    
    int dupes = 0;

    for (unsigned int i = 0; i < s.length(); i++)
    {
        int x = s[i] - 'a';
        int y = 1 << x;

        if ((dupes & (y)) > 0)
        {
            return false; 
        }

        dupes = dupes | (y);

    }

    return true;
    
}

/*
* Main method that reads/parses command line args
* Uses other functions to produce the desired output
*/

int main(int argc, char * const argv[]) 
{
    
    if (!(argc==2))
    {
        cerr << "Usage: " << argv[0] << " <string>" << endl;
        return 1;
    }

    if (is_all_lowercase(argv[1])==false)
    {
        cerr << "Error: String must contain only lowercase letters." << endl;
        return 1;
    }

    if(all_unique_letters(argv[1])==false)
    {
        cout << "Duplicate letters found." << endl;
        return 0;
    }
    
    if(all_unique_letters(argv[1])==true)
    {
        cout << "All letters are unique." << endl;
        return 0;
    }


    return 0;

}