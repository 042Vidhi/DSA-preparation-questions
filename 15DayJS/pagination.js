const arr = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

function paginate(arr,pagesize,pageNumber)
{
    const start = (pageNumber-1)*pagesize;
    const end = start + pagesize;
    return arr.slice(start,end);
}

const pagesize = 5;
const pageNumber = 2;
const pagedata = paginate(arr,pagesize,pageNumber)

console.log(pagedata)

