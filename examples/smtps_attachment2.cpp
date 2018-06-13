/*

smtps_attachment2.cpp
--------------------
 
Connects to SMTP server via SSL and sends a message with attached files.


Copyright (C) 2016, Tomislav Karastojkovic (http://www.alepho.com).

Distributed under the FreeBSD license, see the accompanying file LICENSE or
copy at http://www.freebsd.org/copyright/freebsd-license.html.

*/

#include <iostream>
#include <fstream>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>

using mailio::message;
using mailio::mail_address;
using mailio::smtps;
using mailio::smtp_error;
using mailio::dialog_error;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int , char**) {

	try
	{
		message msg;
		msg.sender(mail_address("SenderName", "senderemail@gmail.com"));
		msg.add_recipient(mail_address("RecipientName", "recipientemail@gmail.com"));
		msg.subject("SMTPS message with attachment");
		msg.content_type(message::media_type_t::TEXT, "plain", "utf-8");
		msg.content("<!DOCTYPE html><html><head><title>Basic Web Page</title></head><body>Hello World!</body></html>");

		ifstream ifs("test.png", std::ios::in | std::ios::binary);
		msg.attach(ifs, "test.png", message::media_type_t::IMAGE, "png");
		ifs.close();

		ifstream ifs1("test.jpg" , std::ios::in | std::ios::binary);
		msg.attach(ifs1, "test.jpg", message::media_type_t::IMAGE, "jpg");
		ifs1.close();

		ifstream ifs2("test.txt");
		msg.attach(ifs2, "test.txt", message::media_type_t::TEXT, "txt");
		ifs2.close();

		ifstream ifs3("test.pdf");
		msg.attach(ifs3, "test.pdf", message::media_type_t::TEXT, "pdf");
		ifs3.close();

		smtps conn("smtp.gmail.com", 587);
		conn.authenticate("senderemail@gmail.com", "senderpassword", smtps::auth_method_t::START_TLS);
		conn.submit(msg);
	}
	catch (smtp_error& exc)
	{
		cout << exc.what() << endl;
	}
	catch (dialog_error& exc)
	{
		cout << exc.what() << endl;
	}

	return EXIT_SUCCESS;
}