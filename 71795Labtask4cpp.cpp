#include <iostream>
#include <vector>
using namespace std;
class RehabTracker
{
    int bme_joints;
    int bme_sessions;
    vector<vector<int>> bme_rom;
public:
    RehabTracker(int bme_joints, int bme_sessions)
    {
        this->bme_joints = bme_joints;
        this->bme_sessions = bme_sessions;

        bme_rom.resize(bme_joints,
                       vector<int>(bme_sessions));
    }
    void enterReadings()
    {
        for (int bme_i = 0; bme_i < bme_joints; bme_i++)
        {
            for (int bme_j = 0; bme_j < bme_sessions; bme_j++)
            {
                cout << "Enter ROM for Joint "
                     << bme_i + 1
                     << ", Session "
                     << bme_j + 1
                     << ": ";

                cin >> bme_rom[bme_i][bme_j];
            }
        }
    }
    void analyseProgress()
    {
        for (int bme_i = 0; bme_i < bme_joints; bme_i++)
        {
            for (int bme_j = 0; bme_j < bme_sessions; bme_j++)
            {
                if (bme_rom[bme_i][bme_j] < 30)
                {
                    cout << "Low Mobility Warning at Joint "
                         << bme_i + 1
                         << " Session "
                         << bme_j + 1
                         << endl;
                }
            }
            int bme_improvement =
               bme_rom[bme_i][bme_sessions - 1] -
                bme_rom[bme_i][0];
            cout << "\nJoint "
                 << bme_i + 1
                 << endl;
            cout << "Improvement: "
                 << bme_improvement
                 << " degrees"
                 << endl;
        }
    }
};
int main()
{
int bme_joints;
int bme_sessions
cout << "Enter number of joints: ";
cin >> bme_joints;
cout << "Enter number of sessions: ";
cin >> bme_sessions;
 RehabTracker bme_tracker(bme_joints, bme_sessions);
 bme_tracker.enterReadings();
 bme_tracker.analyseProgress();
    return 0;
}