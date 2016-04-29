// Main initialization
document.addEventListener('DOMContentLoaded', function() {

    // Global variables
    var video = document.querySelector('video');
	var canvas = document.querySelector('#canvas');
	var startbutton  = document.querySelector('#show_saved_img');
    var audio, audioType;
	width = 320,
	height = 0;

    // Custom video filters
    var iFilter = 0;
    var filters = [
        'grayscale',
        'sepia',
        'blur',
        'brightness',
        'contrast',
        'hue-rotate',
        'hue-rotate2',
        'hue-rotate3',
        'saturate',
        'invert',
        'none'
    ];

    // Get the video stream from the camera with getUserMedia
    navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia ||
        navigator.mozGetUserMedia || navigator.msGetUserMedia;

    window.URL = window.URL || window.webkitURL || window.mozURL || window.msURL;
    if (navigator.getUserMedia) {

        // Evoke getUserMedia function
        navigator.getUserMedia({video: true, audio: false}, onSuccessCallback, onErrorCallback);

        function onSuccessCallback(stream) {
            // Use the stream from the camera as the source of the video element
            video.src = window.URL.createObjectURL(stream) || stream;

             // Autoplay
            video.play();
	        }

        // Display an error
        function onErrorCallback(e) {
            var expl = 'An error occurred: [Reason: ' + e.code + ']';
            console.error(expl);
            alert(expl);
            return;
        }
    } else {
        document.querySelector('.container').style.visibility = 'hidden';
        document.querySelector('.warning').style.visibility = 'visible';
        return;
    }

	function takepicture() {
		canvas.width = width;
		canvas.height = height;
		canvas.getContext('2d').drawImage(video, 0, 0, width, height);
		var dataURL = canvas.toDataURL('image/png');
		showElement("pics_title", "inline-block");
		showElement("pics_comment", "inline-block");
		showElement("container-published", "block");
		showElement("edit-menu", "inline-block");
	}

	startbutton.addEventListener('click', function(ev){
		takepicture();
		ev.preventDefault();
	}, false);


}, false);
