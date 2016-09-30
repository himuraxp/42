var data = "";
$(document).on("page:change", function() {
	$('#firstName').keyup(function(req) {
		if (req.param == 13) {
			event.preventDefault();
			data = this.value;
			$.ajax({
				type: 'GET',
				url: '/Gestion',
				success: function(data) {
					$("<p>Update success !</p>").addClass('created messageTop').appendTo($("#block-gestion"));
				}
			});
			console.log(data);
			return;
		}
	})
});
