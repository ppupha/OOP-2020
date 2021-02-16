#if 0
void draw()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); /* khai báo việc sử dụng
												 chế độ double buffer */
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("spinning rectangle");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); /* đăng ký hàm reshape cho sự kiện cửa sổ bị
							  thay đổi kích thước */
	glutMouseFunc(mouse); /* đăng ký hàm mouse cho sự kiện về chuột */
	glutMainLoop();
}
#endif