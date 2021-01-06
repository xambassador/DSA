(function(){



    function fKnapsack(arr,n,W){
        let currentWeight = 0;
        let fValue = 0;

        for (let i of arr) {
            if (currentWeight + i.weight <= W) {
                currentWeight += i.weight;
                fValue += i.value;
            } else {
                let remainingWeight = W - currentWeight;
                fValue += (remainingWeight / i.weight) * i.value;
                break;
            }
        }
        return fValue;
    }


    (function main(){


        let value = [70,80,90];
        let weight = [15,20,40];
        let maxWeight = 70;

        let Item = [];
        for (let i=0; i<value.length; i++) {
            let item = {};
            item.value = value[i];
            item.weight = weight[i];
            Item.push(item);
        }

        // Sort array
        Item.sort((a,b) => {
            let value1 = parseFloat(a.value/a.weight);
            let value2 = parseFloat(b.value / b.weight);
            if (value1 > value2) {
                return 1;
            }
        });

        console.log(fKnapsack(Item,Item.length,maxWeight));
        

    }());


}());