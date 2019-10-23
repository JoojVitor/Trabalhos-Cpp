var listElement = document.querySelector('#app ul');
var inputElement = document.querySelector('#app input');
var buttonElement = document.querySelector('#app button');

var tasks = JSON.parse(localStorage.getItem('task_list')) || [];

function renderTasks(){
    /*excluir existentes*/
    listElement.innerHTML = '';

    for(task of tasks){
        var taskElement = document.createElement('li');
        var taskText = document.createTextNode(task);

        var linkElement = document.createElement('a');

        linkElement.setAttribute('href', '#');

        var pos = tasks.indexOf(task);
        linkElement.setAttribute('onclick', 'deleteTask(' + pos + ')');

        var linkText = document.createTextNode('Excluir');

        linkElement.appendChild(linkText);

        taskElement.appendChild(taskText);
        taskElement.appendChild(linkElement);

        listElement.appendChild(taskElement);
    }
}

renderTasks();

function addTasks(){
    var taskText = inputElement.value;

    tasks.push(taskText);
    inputElement.value = '';
    renderTasks();
    saveTasks();
}

buttonElement.onclick = addTasks;

function deleteTask(pos){
    tasks.splice(pos, 1);
    renderTasks();
    saveTasks();
}

function saveTasks(){
    localStorage.setItem('task_list', JSON.stringify(tasks));
}
