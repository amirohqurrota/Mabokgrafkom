function tampilkandata(biodata){
    var Nama =(document.biodata.nama.value);
    var Nim =(document.biodata.nim.value);
    var Jns Kelamin =(document.biodata.Jenis Kelamin.value);
    var Prodi =(document.biodata.prodi.value);
    var Angkatan =(document.biodata.angkatan.value);


    function menampilkandata() {
        alert(document.getElementById("tabeldata").rows[1].innerHTML);
    }
    
alert ("Berhasil menambah data")
    document.biodata.nama.value=Nama;
    document.biodata.nim.value=Nim;
    document.biodata.Jenis Kelamin.value=Jns Kelamin;
    document.biodata.prodi.value=Prodi;
    document.biodata.angkatan.value=Angkatan;
}