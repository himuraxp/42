OmniAuth.config.logger = Rails.logger

Rails.application.config.middleware.use OmniAuth::Builder do
  provider :facebook, '701490146612471', '1475d10823ec3977c5d49a5d27320b8b', {:client_options => {:ssl => {:ca_file => Rails.root.join("cacert.pem").to_s}}}
end


