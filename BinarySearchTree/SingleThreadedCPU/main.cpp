#include <iostream>
#include <vector>
#include <queue>
using std::pair;
using std::priority_queue;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

struct Task {
    int enqueueTime, processTime, index;
    Task(int enqueueTime, int processTime, int index) {
        this->enqueueTime = enqueueTime;
        this->processTime = processTime;
        this->index = index;
    }
};

// -----------------------------------------------------------------------------
class Compare {
    public:
    bool operator()(Task &t1, Task &t2) {
        if (t1.processTime == t2.processTime) {
            return t1.index > t2.index;
        }
        return t1.processTime > t2.processTime;
    }
};

// -----------------------------------------------------------------------------
class CompareEnqueueTime {
    public:
    bool operator()(Task &t1, Task &t2) {
        return t1.enqueueTime > t2.enqueueTime;
    }
};

// -----------------------------------------------------------------------------
 vector<int> getOrder(vector<vector<int>>& tasks) {
    int size {(int)tasks.size()};
    // Output array
    vector<int> order(size);
    // Processing Queue is a min priority queue based on process time. Smaller process time is given higher priority.
    priority_queue<Task, vector<Task>, Compare> processingQueue;
    // Waiting Queue is a min priority queue based on enqueue time. Smaller enqueue time is given higher priority.
    priority_queue<Task, vector<Task>, CompareEnqueueTime> waitingQueue;
    // First, Insert all the tasks into the waiting queue.
    for (int i{}; i < size; i++) waitingQueue.push(Task(tasks[i][0], tasks[i][1], i));
    // time is the current time. index is the index of the output array.
    signed long long int time {}, index {};
    // While there are tasks in the waiting queue or the processing queue, we keep processing the tasks.
    while (!processingQueue.empty() || !waitingQueue.empty()) {
        // If there are tasks in the waiting queue and the enqueue time of the top task is less than or equal to the current time,
        // we push the task into the processing queue. We push all tasks that are waiting and that enqueue time is less than or equal to
        // current time.
        while (!waitingQueue.empty() && waitingQueue.top().enqueueTime <= time) {
            processingQueue.push(waitingQueue.top());
            waitingQueue.pop();
        }
        // If processing queue is empty, that means CPU is idle. We set the current time to next task's enqueue time.
        if (processingQueue.empty()) {
            time = waitingQueue.top().enqueueTime;
            continue;
        }

        // Get top task from the processing queue and process it.
        Task task {processingQueue.top()};
        // Pop the task from the processing queue.
        processingQueue.pop();
        // Set the current time to the time when the task is completed.
        time += task.processTime;
        order[index++] = task.index;
    }
    return order;
 }

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    vector<vector<int>> tasks(n);
    for (int i{}; i < n; i++) {
        int enqueueTime, processTime;
        cin >> enqueueTime >> processTime;
        tasks[i] = {enqueueTime, processTime};
    }
    vector<int> order {getOrder(tasks)};
    for (int i{}; i < n; i++) cout << order[i] << " ";
}
