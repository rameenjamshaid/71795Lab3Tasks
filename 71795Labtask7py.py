class HospitalWard:
    def __init__(self, bme_name, bme_totalBeds):
        self.bme_name = bme_name
        self.bme_totalBeds = bme_totalBeds
        self.bme_beds = ["Free"] * bme_totalBeds
    def admitPatient(self, bme_patientName):
        for bme_i in range(self.bme_totalBeds):
            if self.bme_beds[bme_i] == "Free":
                self.bme_beds[bme_i] = "Occupied"
                print(bme_patientName, "assigned to Bed", bme_i + 1)
                return
        print("Ward Full - cannot admit")
    def dischargePatient(self, bme_bedNumber):
        if 1 <= bme_bedNumber <= self.bme_totalBeds:
            if self.bme_beds[bme_bedNumber - 1] == "Occupied":
                self.bme_beds[bme_bedNumber - 1] = "Free"
                print("Bed", bme_bedNumber, "discharged")
            else:
                print("Bed already free")
        else:
            print("Invalid bed number")
bme_ward1 = HospitalWard("Cardiology", 2)
bme_ward2 = HospitalWard("ICU", 1)
bme_ward1.admitPatient("Ali")
bme_ward1.admitPatient("Ahmed")
bme_ward1.admitPatient("Sara")   
bme_ward1.dischargePatient(1)      
bme_ward1.dischargePatient(1)     
bme_ward1.dischargePatient(5)       
bme_ward2.admitPatient("Usman")
bme_ward2.admitPatient("Bilal")     