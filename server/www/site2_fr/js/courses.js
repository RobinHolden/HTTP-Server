function addItem()
{
    var newItem = document.createElement("div");
    if ((newItem.innerHTML = document.getElementById("box").value) == "") {
        return;
    }
    newItem.onclick = removeItem;
    newItem.setAttribute("class", "listelem"); // For CSS
    document.getElementById("list").appendChild(newItem);
    saveList();
}
function removeItem()
{
    document.getElementById("list").removeChild(this);
    saveList();
}
function saveList()
{
    localStorage.storedList = document.getElementById("list").innerHTML;
}
function loadList()
{
    document.getElementById("list").innerHTML = localStorage.storedList;
    for(var i = 0; i < list.children.length; i++) {
        list.children[i].onclick = removeItem;
    }
}

if(localStorage.storedList) {
    loadList();
}
      
var input = document.getElementById("box");
input.addEventListener("keyup", function(event) {
    if (event.keyCode == 13) {
        event.preventDefault();
        document.getElementById("btn").click();
        document.getElementById("box").value = "";
    }
});