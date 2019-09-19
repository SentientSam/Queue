/*
Samuel Lamb
COP 3330
4/26/19
fqueue.cpp
*/

#include <iostream>
#include <tqueue.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>


void DisplayMenu();


fsu::Queue<char> queue('\0');
char ofc;

int main()
{
    std:: cout << "This is a Queue < char > test program\n";
    char input;

    fsu::Queue<char> *qptr = &queue;
    DisplayMenu();

    while(input != 'Q')
    {      
        if(std::cin.eof() == 1) // end of file check implemented 
        {
        std::cout << "Invalid command please restart the program and try again\n";
        exit(EXIT_FAILURE);
        }  



        std::cout << "Enter [command][argument] (\'M\' for menu, \'Q\' to quit): ";
        std::cin >> input;
        switch(input)
        {
            case '1': //Push
            case '+':
            {
                char tval;
                std::cin >> tval;
                qptr -> Push(tval);
                break;
            }
            case '2': //Pop
            case '-':
            {
                qptr -> Pop();
                break;
            }
            case 'C': //Clear
            case 'c':
            {
                qptr -> Clear();
                break;
            }
            case 'F': //Top
            case 'f':
            {
                std::cout << "Front of Queue";
                std::cout << qptr -> Front() << std::endl;
                break;
            }
            case 'E': //Empty
            case 'e':
            {
                if(qptr -> Empty())
                {
                    std::cout << "Queue is empty\n";
                }
                else
                {
                    std::cout << "Queue is not empty\n";
                }
                break;
            }
            case 'S': //Size 
            case 's':
            {
                std::cout << "Queue size     = ";
                std::cout << qptr -> Size() << std::endl;
                break;
            }
            case '=': //Copy test
            {
              
                fsu::Queue<char> queueCopy(queue);
                std::cout << "CopyTest:\n";
                std::cout << "Copied object       size: " << queueCopy.Size() << std::endl;
                std::cout << "                contents: ";
                queueCopy.Display(std::cout);
                std::cout << std::endl;
    
                fsu::Queue<char> queueAssign = queue;
                queueAssign.SetOFC(ofc);
                std::cout << "AssignTest:" << std::endl;
                std::cout << "Original object     size: " << queue.Size() << std::endl;
                std::cout << "                contents: \n";
                queue.Display(std::cout);
                std::cout << "Assignee object     size: " << queueAssign.Size() << std::endl;
                std::cout << "                contents: \n";
                queueAssign.Display(std::cout);
                std::cout << std::endl;                
                
                if(queue.Size() == 0)
                {
                std::cout << "ContTest: Inactive on an empty queue";
                }
                else
                {
                    const int tConst = queue.Front();
                    int tCopy = queue.Front();
                    if (tCopy== tConst)
                    {
                        std::cout << "ConstTest: OK";
                    }
                    else
                    {
                        std::cout << " ConstTest: NOT OK";
                    }
                }

                std::cout << std::endl;
                break;
            }
            case 'D': //Display
            case 'd':
            {
                std::cout << "Queue contents:   ";
                qptr -> Display(std::cout);
                std::cout << std::endl;
                break;
            }
            case 'O': //Set OFC
            case 'o':
            {
                std::cin >> ofc;
                if(ofc == 't' || ofc == 'T')
                {
                    ofc = '\t';
                }
                else if(ofc == 'n' || ofc == 'N')
                {
                    ofc = '\n';
                }
                else if(ofc == '0')
                {
                    ofc = '\0';
                }
                else if( ofc == 'b' || ofc == 'B')
                {
                    ofc = ' ';
                }
                else 
                {
                    std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
                qptr -> SetOFC(ofc);
                break;
            }
            case 'U': //Dump
            case 'u':
            {
                std::cout<<"Queue Dump(): ";
                qptr -> Dump(std::cout); 
                std::cout << std::endl;
                break;
            }
            case 'M': //Display menu
            case 'm':
            {
                DisplayMenu();
                break;
            }
            case 'Q': //quit
            case 'q':
            {
                input = 'Q';
                break;
            }
            default:
            {
                std::cout << "** Unrecognized command -- please try again.\n";

            }

        }//end switch
    }//end while


} //end main
    std::cout << "Have a nice day.\n";
    return 0;
}

void DisplayMenu()
{
    std::cout << "Push(Tval)  .............  + tval or 1 tval\n"
              << "Pop()  ..................  - or 2\n"
              << "Clear()  ................  C\n"
              << "Top()  ..................  T\n"
              << "Empty()  ................  E\n"
              << "Size()  .................  S\n"
              << "Copy tests  .............  =\n"
              << "Display()  ..............  D\n"
              << "SetOFC(ofc)  ............  O 0|b|t|n\n"
              << "Dump()  .................  U\n"
              << "Display this menu  ......  M\n";
}
