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

![alt text](./screenshots/Version1/V1_1_add_student.png)
<br>
B3: Kiểm tra file student.csv xem có thông tin sinh viên đó chưa.<br>
<br> 2. Xoá sinh viên<br>
B1: Sau khi nhập ./main để chạy chương trình, nhập số 2 để xoá sinh viên<br>
B2: Nhập ID theo ảnh để xoá thông tin sinh viên:<br>

![alt text](./screenshots/Version1/V1_2_delete_student.png)
<br>
B3: Kiểm tra file students.csv xem đã xoá sinh viên đó chưa<br>
<br> 3. Cập nhật thông tin sinh viên<br>
B1: Sau khi nhập ./main để chạy chương trình, nhập số 3 để cập nhật thông tin sinh viên<br>
B2: Nhập MSSV muốn cập nhật thông tin<br>
B3: Chọn nội dung muốn cập nhật và cập nhật thông tin theo mẫu hình dưới đây:<br>

![alt text](./screenshots/Version1/V1_3_update_student.png)
<br>
B3: Kiểm tra file students.csv xem đã cập nhật sinh viên đó chưa<br>
<br> 4. Tìm kiếm sinh viên<br>
B1: Sau khi nhập ./main để chạy chương trình, nhập số 4 để tìm kiếm sinh viên<br>
B2: Nhập MSSV hoặc tên sinh viên muốn tìm kiếm và xem kết quả tìm kiếm như hình mẫu:<br>

![alt text](./screenshots/Version1/V1_4_search_student.png)

Version 2.0:<br>

<br>
Cách debug and run trong vscode:<br>
B1: Nhập "g++ main.cpp Student/Funcs/*.cpp Validation/*.cpp Department/*.cpp Status/*.cpp Program/*.cpp LogEvent/*.cpp ShowVersion/*.cpp -IStudent/Headers -IStudent/Validation -IStudent/Department -IStudent/Status -IStudent/Program -IStudent/LogEvent -IStudent/ShowVersion -o main"<br>
B2: Nhập ".\main.exe"<br>

<br>

1. Lưu trữ dữ liệu: Như ở Version 1, em lưu trữ dữ liệu dưới 2 dạng là .csv và .json, các file gồm student/status/program/department (.csv/.json) <br>

![alt text](./screenshots/Version2/V2_4_import_export_data.png)

<br>

2. Cho phép đổi tên + thêm mới Khoa, Tình trạng sinh viên, Chương trình đào tạo <br>

2.1 Thêm mới Khoa<br>
B1: Sau khi chạy chương trình, nhập 1 để load data từ csv, 2 để load từ json<br>
B2: Nhập số 5 để thêm khoa<br>
B3: Nhập tên khoa muốn thêm. VD: Khoa Tieng Han<br>
B4: Kiểm tra xem khoa được thêm trong department(.csv/json) chưa<br>
<br>
Hình minh hoạ:<br>

![alt text](./screenshots/Version2/V2_2_1_add_department.png)
<br>
2.2 Đổi tên khoa <br>
B1: Nhập số 6 để sửa tên khoa<br>
B2: Nhập tên khoa muốn sửa. VD: Khoa Tieng Han<br>
B3: Nhập tên khoa mới. VD: Khoa Tieng Trung<br>
B4: Kiểm tra xem khoa đã thay đổi chưa trong department(.csv/json) và tất cả sinh viên thuộc khoa đó đã được thay đổi tên khoa chưa trong students.csv/student.json.<br>
<br>
Hình minh hoạ: <br>

![alt text](./screenshots/Version2/V2_2_2_update_department.png)

2.3 Thêm mới Tình trạng sinh viên<br>
B1: Sau khi chạy chương trình, nhập 1 để load data từ csv, 2 để load từ json<br>
B2: Nhập số 7 để thêm Tình trạng sinh viên<br>
B3: Nhập tên tình trạng muốn thêm. VD: Dang hoc cao hoc<br>
B4: Kiểm tra xem tình trạng sinh viên được thêm trong status(.csv/json) chưa<br>
<br>

Hình minh hoạ: <br>
![alt text](./screenshots/Version2/V2_2_3_add_status.png)

2.4 Đổi tên Tình trạng sinh viên <br>
B1: Nhập số 8 để sửa tên tình trạng sinh viên<br>
B2: Nhập tên tình trạng muốn sửa. VD: Chua hoc<br>
B3: Nhập tên tình trạng mới. VD: Chua hoc xong<br>
B4: Kiểm tra xem tình trạng sinh viên đã thay đổi chưa trong status(.csv/json) và tất cả sinh viên có tình trạng đó đã được thay đổi tên tình trạng chưa trong students.csv/student.json.<br>

<br>
Hình minh hoạ: <br>

![alt text](./screenshots/Version2/V2_2_4_update_status.png)

2.5 Thêm mới Chương trình<br>
B1: Sau khi chạy chương trình, nhập 1 để load data từ csv, 2 để load từ json<br>
B2: Nhập số 9 để thêm Chương trình<br>
B3: Nhập tên chương trình muốn thêm. VD: Tieng Nhat<br>
B4: Kiểm tra xem chương trình sinh viên được thêm trong program(.csv/json) chưa<br>
<br>

Hình minh hoạ: <br>
![alt text](./screenshots/Version2/V2_2_5_add_program.png)

2.6 Đổi tên Chương trình <br>
B1: Nhập số 10 để sửa tên chương trình sinh viên<br>
B2: Nhập tên chương trình muốn sửa. VD: Tieng Nhat<br>
B3: Nhập tên chương trình mới. VD: Tieng Han<br>
B4: Kiểm tra xem chương trình đã thay đổi chưa trong program(.csv/json) và tất cả sinh viên có chương trình đó đã được thay đổi tên chương trình chưa trong students.csv/student.json.<br>

<br>
Hình minh hoạ: <br>

![alt text](./screenshots/Version2/V2_2_6_update_program.png)

3. Tìm kiếm sinh viên theo khoa hay theo khoa và tên sinh viên:<br>
   3.1 Tìm kiếm sinh viên theo khoa:<br>
   B1: Nhập số 11 để tìm kiếm sinh viên theo khoa.<br>
   B2: Nhập tên khoa muốn tìm. VD: Khoa Tieng Anh thuong mai <br>
   B3: Xem trên màn hình terminal có các sinh viên thuộc khoa đó<br>
   <br>
   Hình minh hoạ: <br>

   ![alt text](./screenshots/Version2/V2_3_1_find_student_by_department.png)

   3.2 Tìm kiếm sinh viên theo khoa và tên sinh viên:<br>
   B1: Nhập số 12 để tìm kiếm sinh viên theo khoa và tên.<br>
   B2: Nhập tên khoa muốn tìm. VD: Khoa Tieng Anh thuong mai <br>
   B4: Nhập tên sinh viên muốn tìm. VD: Thuan <br>
   B4: Xem trên màn hình terminal có các sinh viên thuộc kho và tên đó. <br>
   <br>
   Hình minh hoạ: <br>

   ![alt text](./screenshots/Version2/V2_3_2_find_student_by_department_and_name.png)

4. Hỗ trợ import/export dữ liệu bằng JSON và CSV<br>
   Với các chức năng thêm ở trên, em đã export vô JSON và CSV tự động.<br>
   Nếu muốn import từ JSON hoặc CSV, sau khi chạy chương trình bằng lệnh .\main.exe, nhấn 1 hoặc 2 để import dữ liệu từ JSON/CSV như các thao tác ở trên<br>

<br>
5. Thêm logging mechanism: <br>
Sau khi thao tác các chức năng trên, ấn vào file application.log ở trong thư mục TKPM-EXERCISE để xem các log. <br>

<br>
Hình minh hoạ: <br>

![alt text](./screenshots/Version2/V2_5_logging_mechanism.png)
<br> 6. Thêm show version và ngày build ứng dụng.<br>
B1: Sau khi chạy chương trình, nhập 1 để load data từ csv, 2 để load từ json<br>
B2: Nhập 13 để hiển thị show version <br>
B3: Xem version và ngày build ứng dụng <br>
<br>
Hình minh hoạ: <br>

![alt text](./screenshots/Version2/V2_6_show_version_and_build_date.png)

Version 3.0:<br>
<br>
Cách debug and run trong vscode:<br>
B1: Nhập "g++ main.cpp Student/Funcs/_.cpp Validation/_.cpp Department/_.cpp Status/_.cpp Program/_.cpp LogEvent/_.cpp ShowVersion/\*.cpp -IStudent/Headers -IStudent/Validation -IStudent/Department -IStudent/Status -IStudent/Program -IStudent/LogEvent -IStudent/ShowVersion -o main.exe"<br>
B2: Nhập ".\main.exe"<br>

3.1 + 3.2 + 3.3 MSSV phải là duy nhất, Email phải thuộc một tên miền nhất định và có thể cấu hình động, Số điện thoại phải có định dạng hợp lệ theo quốc gia<br>
B1: Sau khi chạy chương trình, nhập 1 để load data từ csv, 2 để load từ json<br>
B2: Nhập 1 để thêm sinh viên <br>
B3: Nhập một MSSV bất kì (đã có trong students.csv). VD: 22127190 <br>
B4: Hệ thống sẽ báo MSSV đã tồn tại<br>
B5: Làm các bước tương tự như trong hình sau để kiểm tra email, số điện thoại, tình trạng sinh viên:
![alt text](./screenshots/Version3/V3_1+2+3_id+email+phone_validation.png)

3.4 Tình trạng sinh viên chỉ có thể thay đổi theo một số quy tắc<br>
Các tình trạng có thể thay đổi gồm:<br>
Dang hoc --> Bao luu / Da tot nghiep / Dinh chi<br>
Bao luu --> Dang hoc / Dinh chi<br>

B1: Sau khi chạy chương trình, nhập 1 để load data từ csv, 2 để load từ json<br>
B2: Nhập 3 để cập nhật sinh viên <br>
B3: Nhập MSSV. VD: 22127737<brb>
B3: Nhập 11 để cập nhật trạng thái sinh viên <br>
B4: Nhập trạng thái mới. VD: Dang hoc<br>
B5: Hệ thống sẽ báo bị lỗi vì trạng thái cũ của sinh viên 22127737 là Da tot nghiep.<br>
Hình minh hoạ:
![alt text](./screenshots/Version3/V3_4_status_validation.png)

Unit test: Cách chạy: <br>
Các hàm mock của unit test được đặt trong thư mục tests (test_add_student.cpp, test_update_student.cpp)<br>
B1: Trong terminal của IDE, nhập "cmake -B build"<br>
B2: Sau đó nhập "cmake --build build"<br>
B3: Cuối cùng là chạy chương trình: "./build/tests/Debug/runTests.exe"<br>
B4: Kiểm tra code đã được test "PASSED" không như hình dưới đây<br>

![alt text](./screenshots/Version3/V3_5_unit_test.png)
