//closure question

for(var i=0;i<3;i++)
{
    const log =()=>{ //closure because it is accessing i which is outside its scope
        console.log(i);
    }

    setTimeout(log,100);
}
//output : 3 3 3 
//it is because of var if we change it to let i then answer would be 0 1 2