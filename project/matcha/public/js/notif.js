(function($){

	$.fn.notif = function(options){
		var options = $.extend({
			html: '<div class="notification">\
			<div class="notif-left">\
			<i class="fa fa-heart" aria-hidden="true" style="font-size:4em;"></i>\
			</div><div class="notif-right">\
			<h2>{{title}}</h2><p>{{content}}</p>\
			</div>\
			</div>'
		}, options);

		return this.each(function(){

			var $this = $(this);
			var $notifs = $('> .notifications', this);
			var $notif = $(Mustache.render(options.html, options));
			if($notifs.length == 0){
				$notifs = $('<div class="notifications"/>');
				$(this).append($notifs);
			}
			$notifs.append($notif);
			$notif.click(function(event){
				event.preventDefault();
				$notif.slideUp(300, function(){
					$notif.remove();
				});
			})
		})
	}

	$('body').notif({
		title: 'Mon titre',
		content:'Mon contenu',
		icon: '<i class="fa fa-heart" aria-hidden="true" style="font-size:4em;"></i>'
	})

})(jQuery);
