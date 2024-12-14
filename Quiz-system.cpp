#include <iostream>
using namespace std;

void displayQuestion(string question, string options[], int numOptions,int questionNumber ) {
    cout <<"Question "<<questionNumber <<": "<<question<< endl;
    for (int i = 0; i < numOptions; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

bool checkAnswer(int userAnswer, string correctAnswer, string options[]) {
    if (options[userAnswer - 1] == correctAnswer) {
        return true;
    } else {
        return false;
    }
}

void giveFeedback(int score, int totalQuestions) {
    if (score == totalQuestions) {
        cout << "Excellent! You got all the answers correct!" << endl;
    } else if (score >= totalQuestions / 2) {
        cout << "Good job! You got more than half right." << endl;
    } else {
        cout << "Better luck next time. Keep practicing!" << endl;
    }
}

int main() {
    // Arrays to store the questions, options, and correct answers
    string questions[3] = {
        "What is the capital of France?",
        "Which of these is a C++ keyword?",
        "What is 5 + 7?"
    };

    string options[3][4] = {
        {"London", "Berlin", "Paris", "Madrid"},
        {"private", "public", "protected", "constant"},
        {"10", "12", "13", "14"}
    };

    string correctAnswers[3] = {"Paris", "public", "12"};

    int score = 0; // To keep track of the score
    int userAnswer; // To store the user's answer
    int totalQuestions = 3; // Total number of questions

    // Introduction message
    cout << "Welcome to the AI-Powered Quiz!" << endl;
    cout << "In this quiz, you will answer 3 multiple-choice questions." << endl;
    cout << "For each question, choose one of the 4 options by entering the corresponding number (1-4)." << endl;
    cout << "Let's get started!" << endl;

    // Loop through each question
    for (int i = 0; i < totalQuestions; i++) {

        // Display the options using the function
        displayQuestion(questions[i], options[i], 4,i+1);

        // Take the user's answer
        cout << "Enter your answer (1-4): ";
        cin >> userAnswer;

        // Check if the answer is correct using the function
        if (checkAnswer(userAnswer, correctAnswers[i], options[i])) {
            cout << "Correct!" << endl;
            score++; // Increment the score if the answer is correct
        } else {
            cout << "Incorrect. The correct answer is: " << correctAnswers[i] << endl;
        }
    }

    // Display the final score
    cout << "\nYour final score is: " << score << " out of " << totalQuestions << endl;

    // Give feedback based on the score using the function
    giveFeedback(score, totalQuestions);

    return 0;
}