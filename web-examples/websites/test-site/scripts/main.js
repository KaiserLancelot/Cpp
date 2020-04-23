// JavaScript 是一门完备的动态编程语言.当应用于 HTML 文档时, 可为网站提供动态交互特性
// 例如游戏, 动态样式, 动画以及在按下按钮或收到表单数据时做出的响应
// JavaScript 里一切皆对象, 一切皆可储存在变量里

// 数据类型有 String Number Boolean Array Object
// e.g. let myVariable;
// e.g. let array = [1, '李雷', '韩梅梅', 10];

let myImage = document.querySelector("img");

myImage.onclick = function () {
  let mySrc = myImage.getAttribute("src");
  // 运算符等于/不等于 ===/!==
  if (mySrc === "images/firefox-icon.png") {
    myImage.setAttribute("src", "images/firefox2.png");
  } else {
    myImage.setAttribute("src", "images/firefox-icon.png");
  }
};

let myButton = document.querySelector("button");
let myHeading = document.querySelector("h1");

// 定义函数
function setUserName() {
  // 与 alert() 类似会弹出一个对话框, 但是这里需要用户输入数据
  let myName = prompt("请输入你的名字.");

  // 取消提示对话框后值将设置为 null
  if (!myName) {
    setUserName();
  } else {
    // 将数据存储在浏览器中供后续获取
    localStorage.setItem("name", myName);
    myHeading.textContent = "Mozilla 酷毙了, " + myName;
  }
}

if (!localStorage.getItem("name")) {
  setUserName();
} else {
  let storedName = localStorage.getItem("name");
  myHeading.textContent = "Mozilla 酷毙了, " + storedName;
}

// 事件能为网页添加真实的交互能力.它可以捕捉浏览器操作并运行一些代码做为响应
// onclick 点击事件
myButton.onclick = function () {
  setUserName();
};
