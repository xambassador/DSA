(function (){



    function minCost(arr,n,d) {
        let currentCost = arr[0].cost;
        let currentWorker = 0;
        let areaCoverd = 0;

        for(let i =1; i<n; i++) {
            areaCoverd += (arr[i].time - arr[i-1].time) * (arr[currentWorker].speed);
            if (areaCoverd >= d) return curruentCost;

            if (arr[currentWorker].speed < arr[i].speed) {
                currentWorker = i;
                currentCost += arr[i].cost;
            }
        }

        return currentCost;
    }

    (function main(){


        let totalWorkers = 3;
        let totalHouse = 3;
        let workers = [];
        let time = [1,1,1];
        let cost = [2,2,2];
        let speed = [3,1,5];

        for(let i=0; i<totalWorkers; i++) {
            let worker = {};
            worker.time = time[i];
            worker.cost = cost[i];
            worker.speed = speed[i];
            workers.push(worker);
        }

        workers.sort((a,b) => {
            if (a.time === b.time) {
                if (a.speed === b.speed) {
                    if (a.cost <= b.cost) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else if (a.speed > b.speed){
                    return -1;
                } else {
                    return 1;
                }
            } else if(a.time < b.time) {
                return -1;
            } else {
                return 1;
            }
        });

        console.log(minCost(workers,workers.length,totalHouse));

    }());




}());