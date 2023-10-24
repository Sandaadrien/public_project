let h , min , sec , ms , t;
let btn_start , btn_stop , btn_reset;


window.onload = function(){
    sp = document.getElementsByTagName('span')
    btn_start = document.querySelector('.start')
    btn_stop = document.querySelector('.stop')
    btn_reset = document.querySelector('.reset')
    h = 0 , min = 0 , sec = 0 , ms = 0 , t = 0;
}

function update_chrono(){
    ms+=1;
    if(ms==10){
        sec+=1;
        ms = 0;
    }
    if(sec==60){
        min+=1;
        sec = 0;
    }
    if(min==60){
        h+=1;
        min = 0;
    }
    sp[0].innerHTML = h + " h : "
    sp[1].innerHTML = min + " min : "
    sp[2].innerHTML = sec + " sec : "
    sp[3].innerHTML = ms + " ms"
}

function start(){
    t = setInterval(update_chrono , 100)
    btn_start.disabled = true
}

function stop(){
    clearInterval(t);
    btn_start.disabled = false
}

function reset(){
    h = 0 , min = 0 , sec = 0 , ms = 0;
    sp[0].innerHTML = h + " h : "
    sp[1].innerHTML = min + " min : "
    sp[2].innerHTML = sec + " sec : "
    sp[3].innerHTML = ms + " ms"
    btn_start.disabled = false;
}