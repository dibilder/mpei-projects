//Первая функция
//Вызывается при изменении состояния радиокнопок
function handleChange(src) {
  typeSelect = myForm.Type;
    date_start = document.getElementById("date_start");
	date_end = document.getElementById("date_end");
  //Если пользователь хочет купить
  if (src.value == "Buy") {
	//То логично, что он не может купить номер, комнату или койко-место. Удаляем их из списка
	  typeSelect.options[2] = null;
	  typeSelect.options[2] = null;
	  typeSelect.options[2] = null;
	  //И не может выбрать даты
	  date_start.disabled = true;
	  date_end.disabled = true;
	  date_start.parentElement.classList.add('label_disabled')
	  date_end.parentElement.classList.add('label_disabled')
  } else {
	  //Если хочет снять
	  //И список сейчас состоит из двух элементов
	  if (typeSelect.options.length = 2) {
		//То возвращаем комнату, номер и койко-место в список
		var newOption1 = new Option("Комната", "Room");
		var newOption2 = new Option("Номер", "Apartment");
		var newOption3 = new Option("Койко-место", "Bad");
		typeSelect.options[typeSelect.options.length]=newOption1;  
		typeSelect.options[typeSelect.options.length]=newOption2;  
		typeSelect.options[typeSelect.options.length]=newOption3;  		
		//И даты
		date_start.disabled = false;
		date_end.disabled = false;
		date_start.parentElement.classList.remove('label_disabled')
		date_end.parentElement.classList.remove('label_disabled')
	  };
  }
}
//Вторая функция
//Вызывается при изменении списка с вариантами жилья
function handleChange2(src) {
  	rooms = document.getElementById("rooms");
	//Если пользователь хочет снять комнату, номер и койко-место
  if (src.value == "Room" || src.value == "Bad" || src.value == "Apartment") {
	  //То логично, что там не может быть несколько комнат
	  //Количество комнат ставим 1 и замораживаем список
	  rooms.disabled = true;
	  rooms.value = "1";
	  rooms.parentElement.classList.add('label_disabled')

  } else {
	  //Если дом и квартира, то список размораживаем
	  rooms.disabled = false;
	  rooms.parentElement.classList.remove('label_disabled')
  }
}