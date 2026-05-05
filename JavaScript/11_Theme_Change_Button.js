const but_1=document.querySelector(".button1");

let curr_Theme="Light_Theme";

// 1st Approach
// Only One Approach will work At a Time

let body = document.querySelector("body");

but_1.onclick = () => {
    if(curr_Theme!="Dark_Theme"){
        body.style.backgroundColor="Black";
        body.style.color="White";
        curr_Theme="Dark_Theme";
        console.log(curr_Theme);
    }
    else{
        body.style.backgroundColor="White";
        body.style.color="Black";
        curr_Theme="Light_Theme";
        console.log(curr_Theme);
    }
}



// 2nd Approach

const but_2=document.querySelector(".button2");

body = document.querySelector("body");

but_2.onclick = () => {
    if(curr_Theme!="Red_Theme"){
        body.classList.add("Red_Theme");
        body.classList.remove("Green_Theme");
        curr_Theme="Red_Theme";
        console.log(curr_Theme);
    }
    else{
        body.classList.add("Green_Theme");
        body.classList.remove("Red_Theme");
        curr_Theme="Green_Theme";
        console.log(curr_Theme);
    }
}