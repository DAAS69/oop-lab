#include <iostream>
#include <string>
#include <utility>
using namespace std;

// Ball Class
class Ball {
    int x;
    int y;

public:
    Ball(int startX, int startY) : x(startX), y(startY) {}

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    bool is_ball_reached(int ballX, int ballY) {
        return (ballX == 3 && ballY == 3);
    }

    pair<int, int> getPosition() {
        return {x, y};
    }
};

// Robot Class
class Robot {
    int hits;
    string name;

public:
    Robot(string robot_name) : name(robot_name), hits(0) {}

    void hit_ball(Ball* ball, const string &direction) {
        hits++;
        if (direction == "up") {
            ball->setY(ball->getY() + 1);
        } else if (direction == "down") {
            ball->setY(ball->getY() - 1);
        } else if (direction == "left") {
            ball->setX(ball->getX() - 1);
        } else if (direction == "right") {
            ball->setX(ball->getX() + 1);
        }
    }

    int getHits() {
        return hits;
    }

    string getName() {
        return name;
    }
};

// Team Class
class Team {
    string name;
    Robot* player;

public:
    Team(string teamName, string playerName) {
        name = teamName;
        player = new Robot(playerName);
    }

    ~Team() {
        delete player;
    }

    Robot* getPlayer() {
        return player;
    }

    string getTeamName() {
        return name;
    }
};

// Game Class
class Game {
    Team* team1;
    Team* team2;
    Ball* ball;

public:
    Game() {
        team1 = new Team("Team A", "Robot A");
        team2 = new Team("Team B", "Robot B");
        ball = new Ball(0, 0);
    }

    ~Game() {
        delete team1;
        delete team2;
        delete ball;
    }

    // Modified startGame: teams alternate turns and winning team is declared as soon as goal is reached.
    void startGame() {
        cout << "Game started. Initial Ball Position: (" << ball->getX() 
             << ", " << ball->getY() << ")\n";
        string winner = "";
        while (!ball->is_ball_reached(ball->getX(), ball->getY())) {
            // Team A turn.
            team1->getPlayer()->hit_ball(ball, "right");
            cout << team1->getTeamName() << " hit ball: (" 
                 << ball->getX() << ", " << ball->getY() << ")\n";
            if (ball->is_ball_reached(ball->getX(), ball->getY())) {
                winner = team1->getTeamName();
                break;
            }
            // Team B turn.
            team2->getPlayer()->hit_ball(ball, "up");
            cout << team2->getTeamName() << " hit ball: (" 
                 << ball->getX() << ", " << ball->getY() << ")\n";
            if (ball->is_ball_reached(ball->getX(), ball->getY())) {
                winner = team2->getTeamName();
                break;
            }
        }
        cout << "\nFinal Ball Position: (" << ball->getX() << ", " 
             << ball->getY() << ")\n";
        cout << team1->getTeamName() << " total hits: " << team1->getPlayer()->getHits() << "\n";
        cout << team2->getTeamName() << " total hits: " << team2->getPlayer()->getHits() << "\n";
        if (!winner.empty())
            cout << winner << " wins!\n";
        else
            cout << "It's a tie!\n";
    }
};

// Main Function
int main() {
    Game game;
    game.startGame();
    return 0;
}
