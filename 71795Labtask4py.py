class RehabTracker:
    def __init__(self, bme_joints, bme_sessions):
        self.bme_joints = bme_joints
        self.bme_sessions = bme_sessions
        self.bme_rom = []
    def enterReadings(self):
        for bme_i in range(self.bme_joints):
            bme_row = []
            for bme_j in range(self.bme_sessions):
                bme_value = int(input(f"Enter ROM for Joint {bme_i+1}, Session {bme_j+1}: "))
                bme_row.append(bme_value)
            self.bme_rom.append(bme_row)
    def analyseProgress(self):
        for bme_i in range(self.bme_joints):
            for bme_j in range(self.bme_sessions):
                if self.bme_rom[bme_i][bme_j] < 30:
                    print("Low Mobility Warning at Joint",
                          bme_i + 1,
                          "Session",
                          bme_j + 1)
                    bme_improvement = self.bme_rom[bme_i][self.bme_sessions - 1] - self.bme_rom[bme_i][0]
            print("\nJoint", bme_i + 1)
            print("Improvement:", bme_improvement, "degrees")
bme_joints = int(input("Enter number of joints: "))
bme_sessions = int(input("Enter number of sessions: "))
bme_tracker = RehabTracker(bme_joints, bme_sessions)
bme_tracker.enterReadings()
bme_tracker.analyseProgress()