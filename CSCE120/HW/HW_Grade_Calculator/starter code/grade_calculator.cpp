// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    //Variables used for processing the score.
    double examScore = 0;
    double hwScore = 0;
    double readingScore = 0;
    double engagScore = 0;
    double lwScore = 0;
    bool lwRead = 0;
    
    //These variables are the number of each category. (Used for calculating the averages)
    int numExam = 0;
    int numHw = 0;
    int numReading = 0;
    int numEngag = 0;
    int numlw = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);
        

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
            ++numExam;
            examScore += score;

        } else if (category == "final-exam") {
            // TODO(student): process final score
            examScore += score;

        } else if (category == "hw") {
            // TODO(student): process hw score
            ++numHw;
            hwScore += score;

        } else if (category == "lw") {
            // TODO(student): process lw score
            ++numlw;
            lwRead = score;

            if(lwRead == true) {
                lwScore += 100;

            }else{
                lwScore += 0;

            }

        } else if (category == "reading") {
            // TODO(student): process reading score
            ++numReading;
            readingScore += score;

        } else if (category == "engagement") {
            // TODO(student): process engagement score
            ++numEngag;
            engagScore += score;

        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    //Init of variables
    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;

    //Init of temp variables to avoid self assignment
    //check num values to avoid nan (divide by 0 error)
    if(numExam == 0){
        numExam = 1;

    }else{
        exam_average = (examScore)/(numExam + 1);

    }

    if(numHw == 0){
        numHw = 1;

    }else{
        hw_average = (hwScore)/(numHw);

    }

    if(numlw == 0){
        numlw = 1;

    }else{
        lw_average = (lwScore)/(numlw);

    }

    if (numReading == 0){
        numReading = 1;

    }else{
        reading = ((readingScore)/(numReading)) + 15.0;      
        double temp_read = reading;

        if(reading > 100){
            reading = 100;

        }else{       
            reading = temp_read;

        }


    }

    if (numEngag == 0){
        numEngag = 1;
        
    }else{
        engagement = ((engagScore)/(numEngag)) + 15.0;
        double temp_eng = engagement;

        if(engagement > 100){
            engagement = 100;

        }else{        
            engagement = temp_eng;

        }

    }
    
    
    // TODO(student): compute component averages
    /*
    exam_average = (examScore)/(numExam + 1);
    hw_average = (hwScore)/(numHw);
    lw_average = (lwScore)/(numlw);
    reading = ((readingScore)/(numReading)) + 15.0;
    

    if(reading > 100){
        reading = 100;

    }else{       
        reading = reading;

    }

    double engagement = ((engagScore)/(numEngag)) + 15.0;

    if(engagement > 100){
        engagement = 100;

    }else{        
        engagement = engagement;

    }
    */

    // TODO(student): compute weighted total of components
    double weighted_total = ((exam_average*.40)+(hw_average*.40)+(lw_average*.1)+(reading*.05)+(engagement*.05));

    // TODO(student): compute final letter grade
    char final_letter_grade;

    if(weighted_total > 89){
       final_letter_grade = 'A';

    }
    else if(weighted_total > 79){
        final_letter_grade = 'B';

    }else if(weighted_total > 69){
        final_letter_grade = 'C';

    }else if(weighted_total > 59){
        final_letter_grade = 'D';

    }else{
        final_letter_grade = 'F';

    }

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
