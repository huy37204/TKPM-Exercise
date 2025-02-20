# TKPM-Ex<br>

<br>
Cách debug and run trong vscode:<br>
B1: Nhập "g++ main.cpp Student/Funcs/_.cpp Validation/_.cpp -IStudent/Headers -IStudent/Validation -o main"<br>
B2: Nhập "./main"<br>
<br>
Version 1.0:<br>
<br>
1. Thêm sinh viên mới<br>
   Dòng này sẽ xuống dòng ngay sau đây <br>
   Dòng tiếp theo<br>
<br>
   B1: Sau khi nhập ./main để chạy chương trình, nhập số 1 để thêm sinh viên<br>
   B2: Nhập nội dung theo ảnh sau (có kiểm tra tính hợp lệ đối với định dạng email, số điện thoại, tên khoa, tình trạng sinh viên):<br>

![alt text](./screenshots/V1_1_add_student.png)
<br>
B3: Kiểm tra file student.csv xem có thông tin sinh viên đó chưa.<br>
<br> 2. Xoá sinh viên<br>
B1: Sau khi nhập ./main để chạy chương trình, nhập số 2 để xoá sinh viên<br>
B2: Nhập ID theo ảnh để xoá thông tin sinh viên:<br>

![alt text](./screenshots/V1_2_delete_student.png)
<br>
B3: Kiểm tra file students.csv xem đã xoá sinh viên đó chưa<br>
<br> 3. Cập nhật thông tin sinh viên<br>
B1: Sau khi nhập ./main để chạy chương trình, nhập số 3 để cập nhật thông tin sinh viên<br>
B2: Nhập MSSV muốn cập nhật thông tin<br>
B3: Chọn nội dung muốn cập nhật và cập nhật thông tin theo mẫu hình dưới đây:<br>

![alt text](./screenshots/V1_3_update_student.png)
<br>
B3: Kiểm tra file students.csv xem đã cập nhật sinh viên đó chưa<br>
<br> 4. Tìm kiếm sinh viên<br>
B1: Sau khi nhập ./main để chạy chương trình, nhập số 4 để tìm kiếm sinh viên<br>
B2: Nhập MSSV hoặc tên sinh viên muốn tìm kiếm và xem kết quả tìm kiếm như hình mẫu:<br>

![alt text](./screenshots/V1_4_search_student.png)
