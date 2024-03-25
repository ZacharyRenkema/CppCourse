#include <iostream>

void getTicket(int** & tickets, int& rows, int& cols, int& ticketRow, int& ticketCol)
{
    if(tickets == nullptr) //If nullptr
    {
        int** tickets = new int*[2];
        for(int i = 0; i < 2; ++i)
        {
            tickets[i] = new int[3];
        }
    }
    else //Initialize for normal
    {
        int** tickets = new int*[rows];
        for(int i= 0; i < rows; ++i)
        {
            tickets[i] = new int[cols];
        }
    }
    //Find Ticket
    bool foundSeat = false;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(tickets[i][j] == 0)
            {
                foundSeat = true;
                tickets[i][j] = 1; //Indicate that it has been sold
                break;
            }
            else if(tickets[i][j] == 1)
            {
                foundSeat = false;
                continue;
            }
        }
    }
    //Resize Array if no seat was found
    int newRows = rows + 5;

    if(foundSeat == false)
    {
        int** newTickets = new int*[newRows];
        for(int i = 0; i < newRows; ++i)
        {
            newTickets[i] = new int[cols];
        }
        //Copy contents from old to new
        for(int j = 0; j < newRows; ++j)
        {
            for(int k = 0; k < cols; ++k)
            {
                newTickets[j][k] = tickets[j][k];
            }
        }
        //Deallocate old 2D Array
        for(int i = 0; i < rows; ++i)
        {
            delete[] tickets[rows];
        }
        delete[] tickets;
        //Set Old pointer to new address
        rows = newRows;
        tickets = newTickets;
    }


}

int main() 
{
    int**balls = nullptr;
    int rows = 5;
    int cols = 6;
    int ticketRow = 0;
    int ticketCol = 0;

    getTicket(balls, rows, cols, ticketRow, ticketCol);


    return 0;
}