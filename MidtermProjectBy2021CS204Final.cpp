#include <conio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
// Function ProtoTypes
void clearScreen();
void header();
char adminMenu();
char logIn();
char userMenu();
void admin();
void addTeam();
void addIntoArray(string teamName, string ownerName, string player1_name, int player1_age, string player2_name, int player2_age);
void displayTeams();
void removeTeam();
void editTeam();
void manageTeams();
void scheduleMatches();
void matchSchedule();
void displaySchedule();
void editPointTable();
void displayPointTable();
void sorting();
void user();
void reArrangeTeams();
void storeTeamsInFile();
void loadTeamsFromFile();
void storePointsInFile();
void loadPointsFromFile();
void storeScheduleInFile();
void loadScheduleFromFile();
void storeData();
void loadData();
void scheduleInArray(string team1name, string team2name, int date, int month, int time);
void Exit();
void storePassword();
void loadPassword();
void changePassword();
void teamMatch(int edit);
void tournaments();
void addTournaments();
void addTournamentsIntoArrays(string name, int date, int month);
void storeTournamentInFile();
void loadTournamentFromFile();
void searchTeam();
bool athentication();
string parsing(string line, int field);
void recomendation();

// Data Structures
const int MAX_RECORD = 20;
string team_name[MAX_RECORD], owner_name[MAX_RECORD];
string team_player1_name[MAX_RECORD], team_player2_name[MAX_RECORD];
int team_player1_age[MAX_RECORD], team_player2_age[MAX_RECORD];
int team_played_matches[MAX_RECORD], team_won_matches[MAX_RECORD], team_lost_matches[MAX_RECORD];
int team_points[MAX_RECORD];
string team_name_point[MAX_RECORD];

string sorted_team_name[MAX_RECORD], sorted_owner_name[MAX_RECORD];
string sorted_team_player1_name[MAX_RECORD], sorted_team_player2_name[MAX_RECORD];
int sorted_team_player1_age[MAX_RECORD], sorted_team_player2_age[MAX_RECORD];
int sorted_team_played_matches[MAX_RECORD], sorted_team_won_matches[MAX_RECORD], sorted_team_lost_matches[MAX_RECORD];
int sorted_team_points[MAX_RECORD];
int team_count = 0;
string tounamentName[MAX_RECORD];
int tournamentCount = 0;
int tournamentStartDate[MAX_RECORD], tournamentStartMonth[MAX_RECORD];
string smteam1name[MAX_RECORD], smteam2name[MAX_RECORD];
int smdate[MAX_RECORD], smmonth[MAX_RECORD], smtime[MAX_RECORD];
int smcount = 0;
bool loading = true;
string userName = "Pakistan", password = "92";

// Functions
int main()
{
    if (loading)
    {
        loadData();
        loading = false;
    }
    system("cls");
    char login = logIn();
    if (login == '1')
    {

        if (athentication())
        {
            clearScreen();
            admin();
        }
        else
        {
            cout << "Invalid Username or Password.\nTry Again.\n";
            clearScreen();
            main();
        }
    }
    else if (login == '2')
    {
        clearScreen();
        user();
    }
    else if (login == 'E')
    {
        Exit();
    }
    else
    {
        cout << "Invalid Option.\nTry Again.\n";
        clearScreen();
        main();
    }
}
void clearScreen()
{
    //____clear screen_____
    system("pause");
    system("CLS");
}
void header()
{
    // Header
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 2);
    cout << "********************************************" << endl;
    cout << "*       Tournament Management System       *" << endl;
    cout << "********************************************" << endl;
    HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(s, 7);
}
char adminMenu()
{
    // Admin Menu
    header();
    cout << "------ Admin Menu ------" << endl;
    cout << "Choose An Option : " << endl;
    cout << "1.Add Teams." << endl;
    cout << "2.View All Teams." << endl;
    cout << "3.Manage Teams." << endl;
    cout << "4.Schedule Matches." << endl;
    cout << "5.View Schedule." << endl;
    cout << "6.Edit Point Table." << endl;
    cout << "7.View Point Table." << endl;
    cout << "8.Add Tournaments." << endl;
    cout << "9.View Tournaments." << endl;
    cout << "S.Search Team." << endl;
    cout << "P.Change Password." << endl;
    cout << "C.Change Profile." << endl;
    cout << "E.Exit." << endl;
    char option;
    cout << "Your Option : ";
    cin >> option;
    return option;
}
char logIn()
{
    // Login Page
    char login_option;
    header();
    cout << "------ Log In Page ------" << endl;
    cout << "Are you Admin or User : " << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "E.Exit" << endl;
    cout << "Your Option : ";
    cin >> login_option;
    return login_option;
}
char userMenu()
{
    // User Menu
    header();
    cout << "------ User Menu ------" << endl;
    cout << "Choose An option : " << endl;
    cout << "1.View All Teams." << endl;
    cout << "2.View Schedule." << endl;
    cout << "3.View Point Table." << endl;
    cout << "4.View Tournaments." << endl;
    cout << "S.Search Team." << endl;
    cout << "C.Change Profile." << endl;
    cout << "E.Exit." << endl;

    cout << "Your Option : ";
    char option;
    cin >> option;
    return option;
}
void admin()
{
    // Admin Portion
    system("cls");
    while (true)
    {
        char option = adminMenu();

        if (option == 'E')
        {
            Exit();
        }
        clearScreen();
        header();
        if (option == '1')
        {
            // Add Team
            addTeam();
        }
        else if (option == '2')
        {
            // Display Teams
            if (team_count >= 1)
            {
                cout << "Admin Menu > View All Teams :" << endl;
                displayTeams();
                recomendation();
            }
            else
            {
                cout << "You should add at least 1 team to view it." << endl;
            }
        }

        else if (option == '3')
        {
            // Manage Teams
            manageTeams();
        }
        else if (option == '4')
        {
            // Schedule Matches
            scheduleMatches();
        }
        else if (option == '5')
        {
            // View Match Schedule
            if (smcount >= 1)
            {
                matchSchedule();
            }
            else
            {
                cout << "Currently No Schedule is Available." << endl;
            }
        }
        else if (option == '6')
        {
            // Edit Point Table
            editPointTable();
        }
        else if (option == '7')
        {
            // Display Point Table
            if (team_count >= 2)
            {
                displayPointTable();
            }
            else
            {
                cout << "You Should Add At Least 2 Teams to view point Table." << endl;
            }
        }
        else if (option == 'C')
        {
            // Login Page
            system("cls");
            main();
        }
        else if (option == 'P')
        {
            changePassword();
        }
        else if (option == '8')
        {
            addTournaments();
        }
        else if (option == '9')
        {
            tournaments();
        }
        else if (option == 'S')
        {
            searchTeam();
        }
        else
        {
            cout << "You Choosed Invalid Option ." << endl;
        }
        clearScreen();
    }
}
void addTeam()
{
    // Add Team Information
    string teamName = "\0", ownerName;
    string player1_name, player2_name;
    int player1_age, player2_age;
    cout << "Admin Menu > Add Teams :" << endl;
    cout << "Enter Team Name : ";
    cin.ignore();
    getline(cin, teamName);
    cout << "Enter Name of Owner : ";
    getline(cin, ownerName);
    cout << "Enter Players : " << endl;
    cout << "Enter Name of Captain :";
    getline(cin, player1_name);
    cout << "Enter His Age :";
    cin >> player1_age;
    cout << "Enter Name of Vice Captain :";
    cin.ignore();
    getline(cin, player2_name);
    cout << "Enter His Age :";
    cin >> player2_age;
    // Add Team Information into Array
    addIntoArray(teamName, ownerName, player1_name, player1_age, player2_name, player2_age);
}
void addIntoArray(string teamName, string ownerName, string player1_name, int player1_age, string player2_name, int player2_age)
{
    // Add Team Information into Array
    team_name[team_count] = teamName;
    team_name_point[team_count] = teamName;
    owner_name[team_count] = ownerName;
    team_player1_name[team_count] = player1_name;
    team_player1_age[team_count] = player1_age;
    team_player2_name[team_count] = player2_name;
    team_player2_age[team_count] = player2_age;
    team_count++;
}
void displayTeams()
{
    // Display Teams
    cout.setf(ios::left);
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 5);

    cout.width(10);
    cout << "No.";
    cout.width(25);
    cout << "Teams";
    cout.width(25);
    cout << "Owners";
    cout << endl;
    HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(s, 7);
    for (int i = 0; i < team_count; i++)
    {
        cout.width(10);
        cout << i + 1;
        cout.width(25);
        cout << team_name[i];
        cout.width(25);
        cout << owner_name[i];
        cout << endl;
    }
}
void removeTeam()
{
    // Remove Team
    cout << "Admin Menu > Manage Team > Remove Team : " << endl;
    displayTeams();
    cout << "Choose Team You Want To Remove i.e 1 : ";
    int edit;
    cin >> edit;
    int idx = -1;
    if (edit <= team_count)
    {
        for (int i = 0; i < team_count; i++)
        {
            if (team_name[edit - 1] == team_name_point[i])
            {
                idx = i;
            }
        }
        team_name_point[idx] = "\0";
        sorted_team_played_matches[idx] = 0;
        sorted_team_won_matches[idx] = 0;
        sorted_team_lost_matches[idx] = 0;
        sorted_team_points[idx] = 0;
        team_name[edit - 1] = "\0";
        owner_name[edit - 1] = "\0";
        team_player1_name[edit - 1] = "\0";
        team_player1_age[edit - 1] = 0;
        team_player2_name[edit - 1] = "\0";
        team_player2_age[edit - 1] = 0;
        cout << "Team Was Removed." << endl;
        reArrangeTeams();
    }
    else
    {
        cout << "Invalid Team." << endl;
    }
}
void editTeam()
{
    // Edit Team
    cout << "Admin Menu > Manage Team > Edit Team : " << endl;
    displayTeams();
    cout << "Choose Team You Want To Edit i.e 1 : ";
    int edit;
    cin >> edit;
    if (edit <= team_count)
    {

        cout << "Update Team Informations : " << endl;
        cout << "Enter Team Name : ";
        cin.ignore();
        getline(cin, team_name[edit - 1]);
        team_name_point[edit - 1] = team_name[edit - 1];
        cout << "Enter Name of Owner : ";
        getline(cin, owner_name[edit - 1]);
        cout << "Enter Players : " << endl;
        cout << "Enter Name of Captain :";
        getline(cin, team_player1_name[edit - 1]);
        cout << "Enter His Age :";
        cin >> team_player1_age[edit - 1];
        cout << "Enter Name of Vice Captain :";
        cin.ignore();
        getline(cin, team_player2_name[edit - 1]);
        cout << "Enter His Age :";
        cin >> team_player2_age[edit - 1];
    }
    else
    {
        cout << "Invalid Team." << endl;
    }
}
void manageTeams()
{
    // Manage Teams
    if (team_count >= 1)
    {
        cout << "Admin Menu > Manage Teams :" << endl;
        cout << "Choose one Option : " << endl;
        cout << "1.Edit Team." << endl;
        cout << "2.Remove Team." << endl;
        char op;
        cout << "Your Option : ";
        cin >> op;

        if (op == '2')
        {
            removeTeam();

        } // End of op==2 ie Remove Team
        else if (op == '1')
        {
            editTeam();

        } // End of op==1 ie Edit Team
        else
        {
            cout << "Invalid Option" << endl;
        }
    }

    else
    {
        cout << "You Should Add At Least 1 Team To Manage it." << endl;
    }
}
void scheduleMatches()
{
    // Schedule Matches
    string team1name, team2name;
    int date, month, time;
    bool check = false;
    cout << "Main Menu > Schedule Matches : " << endl;
    if (team_count >= 2)
    {
        displayTeams();
        cout << "Enter Name of First Team : ";
        cin.ignore();
        getline(cin, team1name);
        cout << "Enter Name of 2nd Team : ";
        getline(cin, team2name);
        if (team1name != team2name)
        {
            for (int i = 0; i < team_count; i++)
            {
                if (team1name == team_name[i])
                {
                    for (int j = 0; j < team_count; j++)
                    {
                        if (team2name == team_name[j])
                        {

                            while (true)
                            {
                                cout << "Enter Date (1-31) : ";
                                cin >> date;
                                if (date < 1 || date > 31)
                                {
                                    cout << "Invalid Date.\nTry Again." << endl;
                                    continue;
                                }
                                break;
                            }
                            while (true)
                            {
                                cout << "Enter Month (1-12) : ";
                                cin >> month;
                                if (month < 1 || month > 12)
                                {
                                    cout << "Invalid Month.\nTry Again." << endl;
                                    continue;
                                }
                                break;
                            }
                            time = date + (month * 30);
                            cout << "Match is Added in Schedule." << endl;
                            scheduleInArray(team1name, team2name, date, month, time);
                            check = true;
                            break;
                        }
                    }
                }
            }
            if (!check)
            {
                cout << "Team Names Not Found in added Teams.\nTry Again." << endl;
                cout << "Press Any Key to Try Again and 'e' to go to Admin Menu...";
                char ch;
                ch = getch();
                if (ch == 'e')
                    admin();
                system("cls");
                header();
                scheduleMatches();
            }
        }
        else
        {
            cout << "A Team Cannot Play With Itself." << endl;
            cout << "Press Any Key to Try Again and 'e' to go to Admin Menu...";
            char ch;
            ch = getch();
            if (ch == 'e')
                admin();
            system("cls");
            header();
            scheduleMatches();
        }
    }
    else
    {
        cout << "Please Enter At Least 2 Teams To Schedule Matches." << endl;
    }
}
void matchSchedule()
{
    // Sort Matches with respect to Date
    for (int i = 0; i < smcount; i++)
    {
        for (int j = i + 1; j < smcount; j++)
        {
            if (smtime[i] > smtime[j])
            {
                swap(smtime[i], smtime[j]);
                swap(smdate[i], smdate[j]);
                swap(smmonth[i], smmonth[j]);
                swap(smteam1name[i], smteam1name[j]);
                swap(smteam2name[i], smteam2name[j]);
            }
        }
    }
    displaySchedule();
}
void displaySchedule()
{
    // Display Schedule
    cout << "Match Schedule : " << endl;
    for (int i = 0; i < smcount; i++)
    {
        int a = 5;
        if (i < 16)
        {
            a = i + 2;
        }
        else
        {
            i = i / 15;
            a = i + 1;
        }
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, a);

        cout << "Match No." << i + 1 << " : " ;
        cout.setf(ios::left);
        cout.width(25);
        cout<< smteam1name[i] ;
        cout<< "vs\t";
        cout.width(25);
        cout<< smteam2name[i] ;
        cout << " on " << smdate[i] << "/" << smmonth[i] << "/2022" << endl;
    }
    HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(s, 7);
}
void editPointTable()
{
    // Edit Point Table
    cout << "Admin Menu > Edit Point Table : " << endl;
    if (team_count >= 2)
    {
        displayTeams();
        cout << "Choose Team You Want To Edit i.e 1 : ";
        int edit;
        cin >> edit;
        if (edit <= team_count)
        {
            teamMatch(edit);
            recomendation();
        }
        else
        {
            cout << "Invalid Team." << endl;
        }
    }
    else
    {
        cout << "You Should Add Two Teams To Edit Point Table." << endl;
    }
}
void displayPointTable()
{
    // Display Point Table (Sorted)
    cout << "Point Table : " << endl;
    cout << endl;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    cout.setf(ios::left);
    cout.width(25);
    cout << "TeamName";
    cout.width(25);
    cout << "Total Played Matches";
    cout.width(25);
    cout << "Won Matches";
    cout.width(25);
    cout << "Lost Matches";
    cout.width(25);
    cout << "Points";
    cout << endl;
    sorting();
    HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(s, 7);
    for (int i = 0; i < team_count; i++)
    {
        cout.width(25);
        cout << team_name_point[i];
        cout.width(25);
        cout << sorted_team_played_matches[i];
        cout.width(25);
        cout << sorted_team_won_matches[i];
        cout.width(25);
        cout << sorted_team_lost_matches[i];
        cout.width(25);
        cout << sorted_team_points[i];
        cout << endl;
    }
}
void sorting()
{
    // Sort Point Table
    for (int i = 0; i < team_count; i++)
    {
        for (int j = i + 1; j < team_count; j++)
        {
            if (sorted_team_points[i] < sorted_team_points[j])
            {
                swap(sorted_team_points[i], sorted_team_points[j]);
                swap(sorted_team_played_matches[i], sorted_team_played_matches[j]);
                swap(sorted_team_won_matches[i], sorted_team_won_matches[j]);
                swap(sorted_team_lost_matches[i], sorted_team_lost_matches[j]);
                swap(team_name_point[i], team_name_point[j]);
            }
        }
    }
}
void user()
{
    // User Portion
    while (true)
    {
        system("cls");
        char option1 = userMenu();
        if (option1 == 'E')
        {
            Exit();
        }
        clearScreen();
        header();
        if (option1 == '1')
        {
            // View All Teams
            if (team_count >= 1)
            {
                cout << "User Menu > View All Teams :" << endl;
                displayTeams();
                recomendation();
            }
            else
            {
                cout << "Not Enough Data To Show." << endl;
            }
        }
        else if (option1 == '2')
        {
            // View Match Schedule
            if (smcount >= 1)
            {
                matchSchedule();
            }
            else
            {
                cout << "Currently No Schedule is Available." << endl;
            }
        }
        else if (option1 == '3')
        {
            // Display Point Table
            if (team_count < 2)
            {
                cout << "Not Enough Data To Show." << endl;
            }
            else
            {
                displayPointTable();
            }
        }
        else if (option1 == 'C')
        {
            // Change Profile
            system("cls");
            main();
        }
        else if (option1 == '4')
        {
            tournaments();
        }
        else if (option1 == 'S')
        {
            searchTeam();
        }
        else
        {
            cout << "Invalid Option." << endl;
        }
        clearScreen();
    }
}
void reArrangeTeams()
{
    // ReArrange Teams After team is removed
    for (int i = 0; i < team_count; i++)
    {
        for (int j = i + 1; j < team_count; j++)
        {
            if (team_name[i] == "\0")
            {
                swap(team_name[i], team_name[j]);
                swap(team_name_point[i], team_name_point[j]);
                swap(owner_name[i], owner_name[j]);
                swap(team_player1_name[i], team_player1_name[j]);
                swap(team_player1_age[i], team_player1_age[j]);
                swap(team_player2_name[i], team_player2_name[j]);
                swap(team_player2_age[i], team_player2_age[j]);
            }
        }
    }
    for (int i = 0; i < team_count; i++)
    {
        for (int j = i + 1; j < team_count; j++)
        {
            if (team_name_point[i] == "\0")
            {
                swap(team_name_point[i], team_name_point[j]);
                swap(sorted_team_played_matches[i], sorted_team_played_matches[j]);
                swap(sorted_team_won_matches[i], sorted_team_won_matches[j]);
                swap(sorted_team_lost_matches[i], sorted_team_lost_matches[j]);
                swap(sorted_team_points[i], sorted_team_points[j]);
            }
        }
    }
    team_count--;
}
void storeTeamsInFile()
{
    // Store Teams Data in txt File
    fstream file;
    file.open("TeamInformation.txt", ios::out);
    for (int i = 0; i < team_count; i++)
    {
        file << team_name[i] << "," << owner_name[i] << "," << team_player1_name[i]
             << "," << team_player1_age[i] << "," << team_player2_name[i] << ","
             << team_player2_age[i] << endl;
    }
    file.close();
}
void loadTeamsFromFile()
{
    // Load Teams Data in txt File
    fstream file;
    string teamName = "\0", ownerName, name;
    string player1_name, player2_name;
    int player1_age, player2_age;
    int count = 0;
    file.open("TeamInformation.txt", ios::in);
    while (!file.eof())
    {
        getline(file, name);
        count++;
    }
    file.close();
    string line;
    file.open("TeamInformation.txt", ios::in);

    for (int i = 0; i < count - 1; i++)
    {
        getline(file, line);
        teamName = parsing(line, 1);
        ownerName = parsing(line, 2);
        player1_name = parsing(line, 3);
        player1_age = stoi(parsing(line, 4));
        player2_name = parsing(line, 5);
        player2_age = stoi(parsing(line, 6));

        addIntoArray(teamName, ownerName, player1_name, player1_age, player2_name, player2_age);
    }

    file.close();
}
void storePointsInFile()
{
    // Store Teams Points Data in txt File
    fstream file;
    file.open("TeamPoints.txt", ios::out);
    for (int i = 0; i < team_count; i++)
    {
        file << team_name_point[i] << "," << sorted_team_played_matches[i] << ","
             << sorted_team_won_matches[i] << "," << sorted_team_lost_matches[i]
             << "," << sorted_team_points[i] << endl;
    }
    file.close();
}
void loadPointsFromFile()
{
    // Load Teams Points Data in txt File
    fstream file;
    int count = 0;
    string name;
    file.open("TeamPoints.txt", ios::in);
    while (!file.eof())
    {
        getline(file, name);
        count++;
    }
    file.close();
    string line;
    file.open("TeamPoints.txt", ios::in);
    for (int i = 0; i < count - 1; i++)
    {
        getline(file, line);
        team_name_point[i] = parsing(line, 1);
        sorted_team_played_matches[i] = stoi(parsing(line, 2));
        sorted_team_won_matches[i] = stoi(parsing(line, 3));
        sorted_team_lost_matches[i] = stoi(parsing(line, 4));
        sorted_team_points[i] = stoi(parsing(line, 5));
    }
    file.close();
}
void scheduleInArray(string team1name, string team2name, int date, int month, int time)
{
    // Add Schedule in Array
    smteam1name[smcount] = team1name;
    smteam2name[smcount] = team2name;
    smdate[smcount] = date;
    smmonth[smcount] = month;
    smtime[smcount] = time;
    smcount++;
}
void storeScheduleInFile()
{
    // Store Teams Schedule Data in txt File
    fstream file;
    file.open("TeamSchedule.txt", ios::out);
    for (int i = 0; i < smcount; i++)
    {
        file << smteam1name[i] << "," << smteam2name[i] << "," << smdate[i] << ","
             << smmonth[i] << "," << smtime[i] << endl;
    }
    file.close();
}
void loadScheduleFromFile()
{
    // Load Teams Schedule Data in txt File
    fstream file;
    string team1name, team2name, name;
    int date, month, time;
    int count = 0;
    file.open("TeamSchedule.txt", ios::in);
    while (!file.eof())
    {
        getline(file, name);
        count++;
    }
    file.close();
    string line;
    file.open("TeamSchedule.txt", ios::in);

    for (int i = 0; i < count - 1; i++)
    {
        getline(file, line);
        team1name = parsing(line, 1);
        team2name = parsing(line, 2);
        date = stoi(parsing(line, 3));
        month = stoi(parsing(line, 4));
        time = stoi(parsing(line, 5));

        scheduleInArray(team1name, team2name, date, month, time);
    }

    file.close();
}
void storeData()
{
    // Store All Data in txt files
    storePassword();
    storeScheduleInFile();
    storePointsInFile();
    storeTeamsInFile();
    storeTournamentInFile();
}
void loadData()
{
    // Load All Data from txt files
    loadTeamsFromFile();
    loadPassword();
    loadScheduleFromFile();
    loadPointsFromFile();
    loadTournamentFromFile();
}
void Exit()
{
    // Exit Program
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 14);
    cout << "Thanks For Using... \n";
    storeData();
    cout << "Press Any Key To Exit ....";
    getch();
    HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(s, 7);
    system("cls");
    exit(1);
}
void changePassword()
{
    bool find = false;
    cout << "Change Password : " << endl;
    string username, pasword;
    cout << "Enter your Old username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter your Old password: ";
    getline(cin, pasword);
    if (username == userName && pasword == password)
    {
        cout << "Enter your New username: ";
        getline(cin, username);
        cout << "Enter your New password: ";
        getline(cin, pasword);
        for (int i = 0; pasword[i] != '\0'; i++)
        {
            if (pasword[i] == ',')
            {
                find = true;
            }
        }
        for (int i = 0; username[i] != '\0'; i++)
        {
            if (username[i] == ',')
            {
                find = true;
            }
        }
        if (find)
        {
            cout << "You Cannot Add Comma in Your Username or Password." << endl;
        }
        else
        {
            userName = username;
            password = pasword;
            cout << "Password Changed Successfully.\n";
        }
    }
    else
    {
        cout << "Invalid Username or Password.\n";
    }
}
void loadPassword()
{
    fstream file;
    string user, pass;
    string line;
    file.open("Password.txt", ios::in);
    getline(file, line);
    user = parsing(line, 1);
    pass = parsing(line, 2);

    file.close();
    if (user != "\0")
    {
        userName = user;
        password = pass;
    }
}
void storePassword()
{
    fstream file;

    file.open("Password.txt", ios::out);

    file << userName << "," << password << endl;

    file.close();
}
void teamMatch(int edit)
{
    int total, won;
    cout << "No. of Total Played Matches : ";
    cin >> total;
    cout << "Won Matches :";
    cin >> won;
    if (won <= total)
    {
        team_won_matches[edit - 1] = won;
        team_played_matches[edit - 1] = total;
        team_lost_matches[edit - 1] = team_played_matches[edit - 1] - team_won_matches[edit - 1];
        team_points[edit - 1] = 2 * team_won_matches[edit - 1];
        int idx = 0;
        for (int i = 0; i < team_count; i++)
        {
            if (team_name[edit - 1] == team_name_point[i])
            {
                idx = i;
            }
        }

        sorted_team_won_matches[idx] = team_won_matches[edit - 1];
        sorted_team_played_matches[idx] = team_played_matches[edit - 1];
        sorted_team_lost_matches[idx] = team_lost_matches[edit - 1];
        sorted_team_points[idx] = team_points[edit - 1];
        cout << "Point Table updated Successfully." << endl;
    }
    else
    {
        cout << "Won Matches Cannot exceed Total Matches.\n";
        cout << "Enter Carrect Information.\n";
        teamMatch(edit);
    }
}
void tournaments()
{
    cout << "Tournaments : " << endl;
    if (tournamentCount == 0)
    {
        cout << "Due To Covid-19 Tounaments are Postponed." << endl;
        cout << "For New Updates Keep Visiting." << endl;
    }
    else
    {
        for (int i = 0; i < tournamentCount; i++)
        {
            int a = 5;
            if (i < 16)
            {
                a = i + 2;
            }
            else
            {
                i = i / 15;
                a = i + 1;
            }
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, a);

            cout << "-->The " << tounamentName[i] << " is Starting From "
                 << tournamentStartDate[i] << "/" << tournamentStartMonth[i]
                 << "/2022" << endl;
        }
        HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(s, 7);
    }
}
void addTournaments()
{
    cout << "Add Tournaments : " << endl;
    string name;
    int date, month;
    cout << "Enter Name Of Tournament : ";
    cin.ignore();
    getline(cin, name);
    while (true)
    {
        cout << "Enter Starting Date (1-31) : ";
        cin >> date;
        if (date < 1 || date > 31)
        {
            cout << "Invalid Date.\nTry Again." << endl;
            continue;
        }
        break;
    }
    while (true)
    {
        cout << "Enter Starting Month (1-12) : ";
        cin >> month;
        if (month < 1 || month > 12)
        {
            cout << "Invalid Month.\nTry Again." << endl;
            continue;
        }
        break;
    }
    cout << "Tournament is Added Successfully." << endl;
    addTournamentsIntoArrays(name, date, month);
}
void addTournamentsIntoArrays(string name, int date, int month)
{
    tounamentName[tournamentCount] = name;
    tournamentStartDate[tournamentCount] = date;
    tournamentStartMonth[tournamentCount] = month;
    tournamentCount++;
}
void storeTournamentInFile()
{
    fstream file;
    file.open("Tournament.txt", ios::out);
    for (int i = 0; i < tournamentCount; i++)
    {
        file << tounamentName[i] << "," << tournamentStartDate[i] << ","
             << tournamentStartMonth[i] << endl;
    }
    file.close();
}
void loadTournamentFromFile()
{
    fstream file;
    int count = 0;

    string name;
    int date, month;
    file.open("Tournament.txt", ios::in);
    while (!file.eof())
    {
        getline(file, name);
        count++;
    }
    file.close();
    string line;
    file.open("Tournament.txt", ios::in);
    for (int i = 0; i < count - 1; i++)
    {

        getline(file, line);
        name = parsing(line, 1);
        date = stoi(parsing(line, 2));
        month = stoi(parsing(line, 3));

        addTournamentsIntoArrays(name, date, month);
    }
    file.close();
}
void searchTeam()
{
    string name;
    bool b = true;
    cout << "Search Team : " << endl;
    cout << "Enter the Name of Team : ";
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < team_count; i++)
    {
        if (team_name[i] == name)
        {
            cout << "TeamName\tOwner\n";

            cout << team_name[i] << "\t\t" << owner_name[i] << endl;
            b = false;
        }
    }
    if (b)
    {
        cout << "No Team found With This Name. " << endl;
    }
}
bool athentication()
{
    string username, password1;
    cin.ignore();
    cout << "Enter username : ";
    getline(cin, username);
    cout << "Enter Password : ";
    getline(cin, password1);
    if (userName == username && password == password1)
    {
        cout << "Congratulations! Login Successful." << endl;
        return true;
    }
    return false;
}
string parsing(string line, int field)
{
    int comma = 1;
    string item;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            comma++;
        }
        else if (field == comma)
        {
            item = item + line[i];
        }
    }
    return item;
}
void recomendation()
{
    cout << endl;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 3);
    cout << "Recomendation : " << endl;
    HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(s, 7);
    cout << endl;
    cout << "Do You Want to view Point Table ?? ('y' for yes and any key to skip ) : ";
    char ch = getch();
    cout << endl;
    if (ch == 'y' || ch == 'Y')
    {
        system("pause");
        system("cls");
        header();
        displayPointTable();
    }
}