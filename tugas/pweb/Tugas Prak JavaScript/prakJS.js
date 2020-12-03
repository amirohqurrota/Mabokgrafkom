alert ("Selamat datang")
function hitungHasil(){
    var x=document.forms['inputAngka'] ['input1'].value;
    var y=document.forms['inputAngka'] ['input2'].value;
    var a=Number(x)+Number(y);

    document.body.style.backgroundColor = "green";

    var hasilPenjumlahan=document.getElementById("hasil");
    hasilPenjumlahan.innerHTML=a;
}