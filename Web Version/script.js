let students = [];
let course = null;

function addStudent() {
    let name = document.getElementById("studentName").value;

    if (name === "") return;

    students.push(name);
    document.getElementById("output").innerText = "Student added: " + name;

    document.getElementById("courseBox").style.display = "block";
}

function addCourse() {
    let name = document.getElementById("courseName").value;

    if (name === "") return;

    course = name;
    document.getElementById("output").innerText = "Course created: " + name;

    document.getElementById("enrollBox").style.display = "block";
}

function enroll() {
    document.getElementById("output").innerText =
        students.length + " student(s) enrolled in " + course;
}