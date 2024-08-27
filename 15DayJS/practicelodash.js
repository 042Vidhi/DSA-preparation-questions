
var _ = require('lodash');
const foodCourtMenu = [
    {
        id: 1,
        items: {
            Chinese: [
                { name: 'Chowmein', price: '22' },
                { name: 'Fried Rice', price: '25' },
            ],
            Beverages: [
                { name: 'Green Tea', price: '15' },
                { name: 'Cola', price: '10' },
            ],
        },
    },
    {
        id: 2,
        items: {
            FastFood: [
                { name: 'Burger', price: '50' },
                { name: 'Hot Dog', price: '30' },
            ],
            Sides: [
                { name: 'Fries', price: '20' },
                { name: 'Onion Rings', price: '25' },
            ],
        },
    },]
    
const itemId = 1;
const foodCourtData = _.cloneDeep(_.filter(foodCourtMenu, (list) => list.id === itemId));
console.log('foodcourtdata', JSON.stringify(foodCourtData));

const foodCourtDatacomplete = JSON.stringify(foodCourtData);

foodCourtData.forEach((vendor) => {
    console.log(`Vendor ID: ${vendor.id}`);
    Object.keys(vendor.items).forEach((category) => {
      console.log(`  Category: ${category}`);
      vendor.items[category].forEach((item) => {
        console.log(`    - ${item.name}: ${item.price}`);
      });
    });
  });
