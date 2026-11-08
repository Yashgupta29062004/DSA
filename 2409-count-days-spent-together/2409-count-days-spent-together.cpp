class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        // Helper lambda to convert "MM-DD" to the absolute day of the year
        auto dateToDay = [](string date) {
            vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            
            // Extract month and day using string substring
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            
            int totalDays = day;
            // Add all the days of the completely passed months
            for (int i = 0; i < month - 1; i++) {
                totalDays += daysInMonth[i];
            }
            
            return totalDays;
        };
        
        // Convert all string dates to integers
        int startA = dateToDay(arriveAlice);
        int endA = dateToDay(leaveAlice);
        int startB = dateToDay(arriveBob);
        int endB = dateToDay(leaveBob);
        
        // Find the intersection of the two intervals
        int overlap_start = max(startA, startB);
        int overlap_end = min(endA, endB);
        
        // Return the overlap, or 0 if they don't overlap at all
        return max(0, overlap_end - overlap_start + 1);
    }
};