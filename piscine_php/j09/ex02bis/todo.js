$("body").ready(function () {
  var cookie = document.cookie.split(';');
  if (cookie[0]) {
    var patern = /ft_list=(.*)$/;
    var result = patern.exec(cookie[0]);
    if (result != null) {
      var value = result[1].split(',');
      for (var i = value.length - 1; i >= 0; i--) {
        if (value[i]) {
          add_note(value[i], false);
        }
      }
    }
  }
});

function get_note() {
  var todo = new Array;

  var list = $('#ft_list');
  var elem = list.children();
  for (var i = 0; i < elem.length; i++) {
    todo.push(elem[i].innerHTML);
  }
  return (todo);
}

function add_cookie(name, value, time) {
  if (value) {
    var expires = new Date();
    expires.setDate(expires.getDate() + time * 1000);
    document.cookie = name + "=" + value + "; " + expires.toGMTString();
  } else {
    document.cookie = name + "=" + '' + "; " + new Date().toGMTString;
  }
}

function add_note(message, save) {
  var list = $('#ft_list');

  var elem = document.createElement('div');
  elem.classList.add('note');
  elem.innerHTML = message;

  $(elem).bind("click", function(e) {
    if (confirm("Are you sure to remove this note ?")) {
      e.target.remove();
      add_cookie('ft_list', get_note(), 86400);
    }
  });

  list.prepend(elem);
  if (save) {
    console.log("add cookie");
    add_cookie('ft_list', get_note(), 86400);
  }
}

$("#new").click(function() {
  var message = prompt("What\'s the new To do ?");
  if (message) {
    add_note(message, true);
  }
});
