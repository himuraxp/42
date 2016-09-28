/**
 * User.js
 *
 * @description :: TODO: You might write a short summary of how this model works and what it represents here.
 * @docs        :: http://sailsjs.org/documentation/concepts/models-and-orm/models
 */
var bcrypt = require('bcrypt');

module.exports = {
  // connection: 'localMysqlServer',
  attributes: {
     googleId: {
        type: 'string',
        required: true,
        unique: true
      },
      facebookId: {
        type: 'string',
        required: true,
        unique: true
      },
      twitterId: {
        type: 'string',
        required: true,
        unique: true
      },
      id_42: {
        type: 'string',
        required: true,
        unique: true
      },
  		firstName:{
  			type:"string",
  			required:true,
		    minLength: 2
  		},
      lastName:{
        type:"string",
        required:true,
        minLength: 2
      },
      email:{
        type:"email",
        required:"true",
        unique: true
      },
      pseudo:{
        type:"string",
        required:true,
        minLength: 2,
        unique: true
      },
      password:{
        type:"string",
        required:true,
        minLength: 2
      },
      photo:{
        type:"string",
        required:false,
        minLength: 2
      },
      language:{
        type:"string",
        required:true,
      },
      active:{
        type:"integer",
        defaultsTo: '0'
      },
      codeActive:{
        type:"string",
        minLength: 2
      },
  },

  beforeCreate: function(user, cb) {
      bcrypt.genSalt(10, function(err, salt) {
          bcrypt.hash(user.password, salt, function(err, hash) {
            if(err) {
                console.log(err);
                cb(err);
            } else {
                user.password = hash;
                // console.log(hash);
                cb(null, user);
            }
          });
      });
  }
};
