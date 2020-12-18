//
//  main.cpp
//  a3_q1
//
//  Created by Laura Persichini on 2020-10-31.
//  Copyright © 2020 Laura Persichini. All rights reserved.
/*

 Project: Soccer game simulation
 Purpose: Write a program that simulates a game of soccer where two teams are playing a single game (team A vs team B)
 Due date: November 1, 2020
 Warning: I used a time delay between the events to enhance the experience. This will explain the delay between events.
 */

/*
 To test the program, I ran it multiple times to assess both the randomness of the numbers being generated,
 and that the logic behind the code was correct. I used a pencil and paper to tally statistics for the teams
 to ensure that the values being ouputted were accurate and that the logic I used to create the program
 was valid. As I was creating the program, I tested the blocks of code as they were being written to avoid
 not being able to identify errors once more code was written. For example, the number generator was outputting
 the same value. I tested this and realized the error was being caused by the number generator using time
 as the seed. Altering the seed to null fixed this problem. Also, I ran my program until I had seen that all of the
 possible events had occured. One limitation of this program could be that it is not an exact simulation of soccer
 in real life. For example, in real-life soccer, the teams are often not evenly matched, so it would be unlikely
 that there is complete randomness in the outcomes.
 */
/*
 SAMPLE OUTPUT 1:
 Team B has committed a foul close to  the goal and Team A was awarded a penalty kick!
  The shot was off goal! Better luck next time Team A!
  Yellow card! Watch out!

  Team A has committed a foul close to the goal and Team B was awarded a penalty kick!
  Amazing save from Team A's goalie!
  Yellow card! Watch out!

  Team A has committed a foul and Team B has been awarded a free kick!
  Amazing save from Team A's goalie!

  Team A has shot at target...
  Amazing save from Team B's goalie!

  Team B has shot at target...
  The shot was off goal! Better luck next time Team B!

  Team A has committed a foul and Team B has been awarded a free kick!
  Amazing save from Team A's goalie!
  Yellow card! Watch out!

 -------------------------------------------------
 Here are the game stats at halftime:

 Team A score: 0
 Team B score: 0

 Team A shots on goal: 1
 Team B shots on goal: 3

 Team A shots off goal: 1
 Team B shots off goal: 1

 Team A shots blocked by goalie: 3
 Team B shots blocked by goalie: 1

 Team A shots blocked by player: 0
 Team B shots blocked by player: 0

 Team A fouls: 3
 Team B fouls: 1

 Team A yellow cards: 2
 Team B yellow cards: 1

 Team A red cards: 1
 Team B red cards: 0
 -------------------------------------------------
  Team B has committed a foul close to  the goal and Team A was awarded a penalty kick!
  The shot was off goal! Better luck next time Team A!
  Yellow card! Watch out!

  Team A has committed a foul and Team B has been awarded a free kick!
  The shot was off goal! Better luck next time Team B!

  Team A has committed a foul and Team B has been awarded a free kick!
  Great block from Team A player! Good try, Team B!
  Yellow card! Watch out!

  Team B has shot at target...
  Great block from Team A player! Good try, Team B!

  Team B has committed a foul close to  the goal and Team A was awarded a penalty kick!
  Team A has scored a goal! Fantastic shot!
  No card awarded, how lucky!

  Team A has committed a foul close to the goal and Team B was awarded a penalty kick!
  Amazing save from Team A's goalie!
  Oh no! Red card!

  Team A has shot at target...
  The shot was off goal! Better luck next time Team A!

  Team A has committed a foul and Team B has been awarded a free kick!
  Team B has scored a goal! Fantastic shot!
  No card awarded, how lucky!

 -------------------------------------------------
 Here is a summary of the game stats:

 Team A score: 1
 Team B score: 1

 Team A shots on goal: 2
 Team B shots on goal: 5

 Team A shots off goal: 3
 Team B shots off goal: 2

 Team A shots blocked by goalie: 4
 Team B shots blocked by goalie: 1

 Team A shots blocked by player: 2
 Team B shots blocked by player: 0

 Team A fouls: 7
 Team B fouls: 3

 Team A yellow cards: 3
 Team B yellow cards: 2

 Team A red cards: 3
 Team B red cards: 0
 -------------------------------------------------
 Program ended with exit code: 0
 
 SAMPLE OUTPUT 2:
 Team B has shot at target...
  Great block from Team A player! Good try, Team B!

  Team A has shot at target...
  Team A has scored a goal! Fantastic shot!

  Team A has committed a foul and Team B has been awarded a free kick!
  Team B has scored a goal! Fantastic shot!

 -------------------------------------------------
 Here are the game stats at halftime:

 Team A score: 1
 Team B score: 1

 Team A shots on goal: 1
 Team B shots on goal: 1

 Team A shots off goal: 0
 Team B shots off goal: 0

 Team A shots blocked by goalie: 0
 Team B shots blocked by goalie: 0

 Team A shots blocked by player: 1
 Team B shots blocked by player: 0

 Team A fouls: 1
 Team B fouls: 0

 Team A yellow cards: 0
 Team B yellow cards: 0

 Team A red cards: 1
 Team B red cards: 0
 -------------------------------------------------
  Team A has committed a foul close to the goal and Team B was awarded a penalty kick!
  Amazing save from Team A's goalie!
  Oh no! Red card!

  Team B has committed a foul and Team A has been awarded a free kick!
  Team A has scored a goal! Fantastic shot!
  No card awarded, how lucky!

  Team B has committed a foul close to  the goal and Team A was awarded a penalty kick!
  The shot was off goal! Better luck next time Team A!
  Oh no! Red card!

  Team B has committed a foul and Team A has been awarded a free kick!
  Great block from Team B player! Good try, Team A!
  No card awarded, how lucky!

  Team A has committed a foul close to the goal and Team B was awarded a penalty kick!
  Amazing save from Team A's goalie!
  Yellow card! Watch out!

 -------------------------------------------------
 Here is a summary of the game stats:

 Team A score: 2
 Team B score: 1

 Team A shots on goal: 2
 Team B shots on goal: 3

 Team A shots off goal: 1
 Team B shots off goal: 0

 Team A shots blocked by goalie: 2
 Team B shots blocked by goalie: 0

 Team A shots blocked by player: 1
 Team B shots blocked by player: 1

 Team A fouls: 3
 Team B fouls: 3

 Team A yellow cards: 1
 Team B yellow cards: 0

 Team A red cards: 2
 Team B red cards: 1
 -------------------------------------------------
 Program ended with exit code: 0
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

// initialize what variables a team struct has
struct team {
    int score;
    int shots_on_goal;
    int shots_off_goal;
    int blocked_shots_goalie;
    int blocked_shots_player;
    int fouls;
    int yellow_cards;
    int red_cards;
};

// determine number of events [1,20] (get random number from 1-20)
int determine_num_events() {
    int random_variable = rand();
    int num_events = random_variable % (20 - 1 + 1) + 1;
    return num_events;
}

// determine what will happen in each event
// for each event, generate a number between [1,6]
int determine_event_activities() {
    int event_activity;
    event_activity = rand() % (6 - 1 + 1) + 1;
    return event_activity;
}

// event activity 1
// Team A has shot at target
void event_activity_1(team &team_a, team &team_b) { // the values for team structs will change
    int rand_num = rand() % 4; // generate random number (0,1,2 or 3)
    cout << " Team A has shot at target... " << endl;
    
    switch (rand_num) {
        case 0:
            // goal
            // team A increase score by 1
            team_a.score += 1;
            cout << " Team A has scored a goal! Fantastic shot!" << endl;
            // team A increase shots on goal (shooting at net of team B)
            team_a.shots_on_goal += 1;
            break;
        case 1:
            // shot on goal but saved by goalkeeper/defender
            // team A increase shots on goal by one
            team_a.shots_on_goal += 1;
            // team B increase blocked shots goalie by one
            team_b.blocked_shots_goalie += 1;
            cout << " Amazing save from Team B's goalie! " << endl;
            break;
        case 2:
            //shot off goal
            //team A shots off goal by 1
            team_a.shots_off_goal += 1;
            cout << " The shot was off goal! Better luck next time Team A!" << endl;
            break;
        case 3:
            // shot blocked by player
            //team B increase shots blocked by player by 1
            team_b.blocked_shots_player += 1;
            cout << " Great block from Team B player! Good try, Team A!" << endl;
            break;
    }
}

// event activity 2
// team B has made a shot at the target
void event_activity_2(team &team_a, team &team_b) {
     int rand_num = rand() % 4; // the possible cases are (0,1,2, and 3)
     cout << " Team B has shot at target... " << endl;
    
     switch (rand_num) {
         case 0:
             // goal
             // team B increase score by 1
             team_b.score += 1;
              cout << " Team B has scored a goal! Fantastic shot! " << endl;
             // team B increase shots on goal (shooting at net of team A)
             team_b.shots_on_goal += 1;
             break;
         case 1:
             // shot on goal but saved by goalkeeper/defender
             // team B increase shots on goal by one
             team_b.shots_on_goal += 1;
             // team A increase blocked shots goalie by one
             team_a.blocked_shots_goalie += 1;
             cout << " Amazing save from Team A's goalie! " << endl;
             break;
         case 2:
             //shot off goal
             //team B shots off goal by 1
             team_b.shots_off_goal += 1;
             cout << " The shot was off goal! Better luck next time Team B! " << endl;
             break;
         case 3:
             // shot blocked by player
             //team A increase shots blocked by player by 1
             team_a.blocked_shots_player += 1;
             cout << " Great block from Team A player! Good try, Team B! " << endl;
             break;
     }
}

// event activity 3
// team B foul and team A gets a free kick
void event_activity_3(team &team_a, team &team_b) {
    team_b.fouls += 1; // team B recieves a foul no matter the outcome of free kick
    int rand_num = rand() % 4; // the first random number has possibilities of 0,1,2, and 3
    int rand_num_2 = rand() % 3; // the second random number has possiblilites of 0,1, and 2
    cout << " Team B has committed a foul and Team A has been awarded a free kick! " << endl;
    
    switch (rand_num) { // using the first random number
        case 0:
            // goal
            // team A increase score by 1
            team_a.score += 1;
            cout << " Team A has scored a goal! Fantastic shot!" << endl;
            // team A increase shots on goal (shooting at net of team A)
            team_a.shots_on_goal += 1;
            break;
        case 1:
            // shot on goal but saved by goalkeeper/defender
            // team A increase shots on goal by one
            team_a.shots_on_goal += 1;
            // team B increase blocked shots goalie by one
            team_b.blocked_shots_goalie += 1;
            cout << " Amazing save from Team B's goalie! " << endl;
            break;
        case 2:
            //shot off goal
            //team A shots off goal by 1
            team_a.shots_off_goal += 1;
            cout << " The shot was off goal! Better luck next time Team A! " << endl;
            break;
        case 3:
            // shot blocked by player
            //team B increase shots blocked by player by 1
            team_b.blocked_shots_player += 1;
            cout << " Great block from Team B player! Good try, Team A! " << endl;
            break;
    }
    
    switch (rand_num_2) { // using the second random number
        case 0:
            // no card
            cout << " No card awarded, how lucky! " << endl;
            break;
        case 1:
            // yellow card given
            // team B yellow card increase by 1
            team_b.yellow_cards += 1;
            cout << " Yellow card! Watch out! " << endl;
            break;
            
        case 2:
            // red card given
            // team B red card increase by 1
            team_b.red_cards +=1;
            cout << " Oh no! Red card! " << endl;
            break;
    }
}

// event activity 4
// team A foul and team B gets free kick
void event_activity_4(team &team_a, team &team_b) {
    team_a.fouls += 1; // team A recieves foul no matter the outcome of free kick
   int rand_num = rand() % 4;
   int rand_num_2 = rand() % 3;
    cout << " Team A has committed a foul and Team B has been awarded a free kick! " << endl;
   
    switch (rand_num) {
            case 0:
                // goal
                // team B increase score by 1
                team_b.score += 1;
                cout << " Team B has scored a goal! Fantastic shot!" << endl;
                // team B increase shots on goal (shooting at net of team A)
                team_b.shots_on_goal += 1;
                break;
            case 1:
                // shot on goal but saved by goalkeeper/defender
                // team B increase shots on goal by one
                team_b.shots_on_goal += 1;
                // team A increase blocked shots goalie by one
                team_a.blocked_shots_goalie += 1;
                cout << " Amazing save from Team A's goalie! " << endl;
                break;
            case 2:
                // shot off goal
                // team B shots off goal by 1
                team_b.shots_off_goal += 1;
                cout << " The shot was off goal! Better luck next time Team B! " << endl;
                break;
            case 3:
                // shot blocked by player
                // team A increase shots blocked by player by 1
                team_a.blocked_shots_player += 1;
                cout << " Great block from Team A player! Good try, Team B! " << endl;
                break;
    }
       
   switch (rand_num_2) {
       case 0:
           // no card
           cout << " No card awarded, how lucky! " << endl;
           break;
       case 1:
           // yellow card given
           // team A yellow card increase by 1
           team_a.yellow_cards += 1;
           cout << " Yellow card! Watch out! " << endl;
           break;
           
       case 2:
           //red card given
           // team A red card increase by 1
           team_a.red_cards +=1;
           break;
   }
}

// event activity 5
// team B foul close to goal, team a gets penalty kick
void event_activity_5(team &team_a, team &team_b) {
    team_b.fouls += 1;
    int rand_num = rand() % 3; // generate a random number (0,1,2)
    int rand_num_2 = rand() % 3; // generate a second random number (0,1,2)
    cout << " Team B has committed a foul close to  the goal and Team A was awarded a penalty kick! " << endl;
    
    switch (rand_num) {
        case 0:
            // team A has scored, increase score by 1
            //team A shots on goal increase by 1
            team_a.score += 1;
            cout << " Team A has scored a goal! Fantastic shot!" << endl;
            team_a.shots_on_goal += 1;
            break;
            
        case 1:
            // team A shot on goal, saved by goalie
            //team A shot on goal increase by 1
            //team B goalie blocked shots increase by 1
            team_a.shots_on_goal += 1;
            team_b.blocked_shots_goalie += 1;
            cout << " Amazing save from Team B's goalie! " << endl;
            break;
            
        case 2:
            // team A shot off goal
            // team A increase shots off goal
            team_a.shots_off_goal += 1;
            cout << " The shot was off goal! Better luck next time Team A! " << endl;
            break;
    }
    
    switch (rand_num_2) {
        case 0:
            // no card given
            cout << " No card awarded, how lucky! " << endl;
            break;
        case 1:
            // yellow card given
            // team B yellow card increase by 1
            team_b.yellow_cards += 1;
            cout << " Yellow card! Watch out! " << endl;
            break;
            
        case 2:
            //red card given
            // team B red card increase by 1
            team_b.red_cards +=1;
            cout << " Oh no! Red card! " << endl;
            break;
    }
}

// event activity 6
// team A foul close to goal, team B gets penalty kick
void event_activity_6(team &team_a, team &team_b) {
    team_a.fouls += 1;
    int rand_num = rand() % 3;
    int rand_num_2 = rand() % 3;
    cout << " Team A has committed a foul close to the goal and Team B was awarded a penalty kick! " << endl;
    
    switch (rand_num) {
        case 0:
            // team B has scored, increase score by 1
            //team B shots on goal increase by 1
            team_b.score += 1;
            cout << " Team B has scored a goal! Fantastic shot!" << endl;
            team_b.shots_on_goal += 1;
            break;
            
        case 1:
            // team B shot on goal, saved by goalie
            //team B shot on goal increase by 1
            //team A goalie blocked shots increase by 1
            team_b.shots_on_goal += 1;
            team_a.blocked_shots_goalie += 1;
            cout << " Amazing save from Team A's goalie! " << endl;
            break;
            
        case 2:
            // team B shot off goal
            // team B increase shots off goal
            team_b.shots_off_goal += 1;
            cout << " The shot was off goal! Better luck next time Team B! " << endl;
            break;
    }
    
    switch (rand_num_2) {
        case 0:
            // no card given
            cout << " No card awarded, how lucky! " << endl;
            break;
        case 1:
            // yellow card given
            // team A yellow card increase by 1
            team_a.yellow_cards += 1;
            cout << " Yellow card! Watch out! " << endl;
            break;
            
        case 2:
            //red card given
            // team A red card increase by 1
            team_a.red_cards +=1;
            cout << " Oh no! Red card! " << endl;
            break;
    }
}
  
int main(int argc, const char * argv[]) {
    
    srand((unsigned) time(NULL)); // seed the random function
    // creating an instance of the team struct for team a with all of the stats to be outputted at
    // halftime and at the end of the game
    team team_a;
    team_a.score = 0;
    team_a.shots_on_goal = 0;
    team_a.shots_off_goal = 0;
    team_a.blocked_shots_goalie = 0;
    team_a.blocked_shots_player = 0;
    team_a.fouls = 0;
    team_a.yellow_cards = 0;
    team_a.red_cards = 0;
    
    // creating an instance of the team struct for team b with all of the stats to be outputted at
    // halftime and at the end of the game
    team team_b;
    team_b.score = 0;
    team_b.shots_on_goal = 0;
    team_b.shots_off_goal = 0;
    team_b.blocked_shots_goalie = 0;
    team_b.blocked_shots_player = 0;
    team_b.fouls = 0;
    team_b.yellow_cards = 0;
    team_b.red_cards = 0;
    
    // assign the return of the determine_num_events function to a variable
    int amount_events = determine_num_events();
    for (int i = 1; i <= amount_events; i++) { // have number of events equal to amount_events
        int event_activity = determine_event_activities();
        // output halftime stats, if amount_events is odd, floor function will round down
        if (i == floor(amount_events / 2)) {
            cout << "-------------------------------------------------" << endl;
            cout << "Here are the game stats at halftime: " << endl;
            cout << endl;
            cout << "Team A score: " << team_a.score << endl;
            cout << "Team B score: " << team_b.score << endl;
            cout << endl;
            cout << "Team A shots on goal: " << team_a.shots_on_goal << endl;
            cout << "Team B shots on goal: " << team_b.shots_on_goal << endl;
            cout << endl;
            cout << "Team A shots off goal: " << team_a.shots_off_goal << endl;
            cout << "Team B shots off goal: " << team_b.shots_off_goal << endl;
            cout << endl;
            cout << "Team A shots blocked by goalie: " << team_a.blocked_shots_goalie << endl;
            cout << "Team B shots blocked by goalie: " << team_b.blocked_shots_goalie << endl;
            cout << endl;
            cout << "Team A shots blocked by player: " << team_a.blocked_shots_player << endl;
            cout << "Team B shots blocked by player: " << team_b.blocked_shots_player << endl;
            cout << endl;
            cout << "Team A fouls: " << team_a.fouls << endl;
            cout << "Team B fouls: " << team_b.fouls << endl;
            cout << endl;
            cout << "Team A yellow cards: " << team_a.yellow_cards << endl;
            cout << "Team B yellow cards: " << team_b.yellow_cards << endl;
            cout << endl;
            cout << "Team A red cards: " << team_a.red_cards << endl;
            cout << "Team B red cards: " << team_b.red_cards << endl;
            cout << "-------------------------------------------------" << endl;
        }
        
        // calling which functions to run depending on the the event activity
        switch (event_activity) {
            case 1:
                event_activity_1(team_a, team_b);
                cout << endl;
                break;
            case 2:
                event_activity_2(team_a, team_b);
                cout << endl;
                break;
            case 3:
                event_activity_3(team_a, team_b);
                cout << endl;
                break;
            case 4:
                event_activity_4(team_a, team_b);
                cout << endl;
               break;
            case 5:
                event_activity_5(team_a, team_b);
                cout << endl;
               break;
            case 6:
                event_activity_6(team_a, team_b);
                cout << endl;
               break;
            
        }
        this_thread::sleep_for(1500000000ns); // time delay of 1.5 sec between events
    }
    
    // output stats at the end of the game
    cout << "-------------------------------------------------" << endl;
    cout << "Here is a summary of the game stats: " << endl;
    cout << endl;
    cout << "Team A score: " << team_a.score << endl;
    cout << "Team B score: " << team_b.score << endl;
    cout << endl;
    cout << "Team A shots on goal: " << team_a.shots_on_goal << endl;
    cout << "Team B shots on goal: " << team_b.shots_on_goal << endl;
    cout << endl;
    cout << "Team A shots off goal: " << team_a.shots_off_goal << endl;
    cout << "Team B shots off goal: " << team_b.shots_off_goal << endl;
    cout << endl;
    cout << "Team A shots blocked by goalie: " << team_a.blocked_shots_goalie << endl;
    cout << "Team B shots blocked by goalie: " << team_b.blocked_shots_goalie << endl;
    cout << endl;
    cout << "Team A shots blocked by player: " << team_a.blocked_shots_player << endl;
    cout << "Team B shots blocked by player: " << team_b.blocked_shots_player << endl;
    cout << endl;
    cout << "Team A fouls: " << team_a.fouls << endl;
    cout << "Team B fouls: " << team_b.fouls << endl;
    cout << endl;
    cout << "Team A yellow cards: " << team_a.yellow_cards << endl;
    cout << "Team B yellow cards: " << team_b.yellow_cards << endl;
    cout << endl;
    cout << "Team A red cards: " << team_a.red_cards << endl;
    cout << "Team B red cards: " << team_b.red_cards << endl;
    cout << "-------------------------------------------------" << endl;

    return 0;
}
 
