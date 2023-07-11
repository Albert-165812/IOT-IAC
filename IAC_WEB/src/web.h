const char Web[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        *,
        *:before,
        *:after {
        box-sizing: border-box;
        }
        * {
        margin: 0;
        padding: 0;
        font: inherit;
        }
        img,
        picture,
        svg,
        video {
        display: block;
        max-width: 100%;
        }
        input,
        select,
        textarea {
        background-color: transparent;
        outline: none;
        }
        button {
        cursor: pointer;
        background-color: transparent;
        outline: none;
        border: 0;
        }
        body {
        min-height: 100vh;
        font-weight: 400;
        font-size: 16px;
        line-height: 1;
        background-color: rgb(249, 241, 230);
        }
        #template {
            --row :36px;
            --col_1 :129px;
            --col :102px;
            flex-grow: 1;
            padding: 0.4rem 0;
            display: grid;
            grid-gap: 4px;
            grid-template-rows: var(--row) var(--col_1) var(--row) var(--col) var(--row) var(--col) var(--row) var(--col);
            grid-template-areas: 
            "row_1 row_1 row_1"
            "col_11 col_12 col_13"
            "row_2 row_2 row_2"
            "col_21 col_22 col_23"
            "row_3 row_3 row_3"
            "col_31 col_32 col_33"
            "row_4 row_4 row_4"
            "col_41 col_42 col_43";
        }
        .template_header_1{
            grid-area: row_1;
            background-color: aquamarine;
            border-radius: 16px;
        }
        .template_header_2{
            grid-area: row_2;
            background-color: bisque;
            border-radius: 16px;
        }
        .template_header_3{
            grid-area: row_3;
            background-color: cadetblue;
            border-radius: 16px;
        }
        .template_header_4{
            grid-area: row_4;
            background-color: aquamarine;
            border-radius: 16px;
        }
        .template_content_1 {
            grid-area: col_11;
        }
        .template_content_2 {
            grid-area: col_12;
        }
        .template_content_3 {
            grid-area: col_13;
        }
        .template_content_3>.content_content,
        .template_content_6>.content_content,
        .template_content_9>.content_content,
        .template_content_12>.content_content {
            width: 100%;
            height: calc(100% - 28px);
        }
        .template_content_3>.content_content center,
        .template_content_6>.content_content center,
        .template_content_9>.content_content center,
        .template_content_12>.content_content center{
            width: 100%;
            height: 100%;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .template_content_4 {
            grid-area: col_21;
        }
        .template_content_5 {
            grid-area: col_22;
        }
        .template_content_6 {
            grid-area: col_23;
        }
        .template_content_7 {
            grid-area: col_31;
        }
        .template_content_8 {
            grid-area: col_32;
        }
        .template_content_9 {
            grid-area: col_33;
        }
        .template_content_10 {
            grid-area: col_41;
        }
        .template_content_11 {
            grid-area: col_42;
        }
        .template_content_12 {
            grid-area: col_43;
        }
        .btn {
            padding: 8px 4px;
        }
        .btn:hover {
            display: inline-block;
            opacity: 0.7;
            cursor: pointer;
            background-color: aquamarine;
            border-radius: 16px;
        }
        .box_weather {
            background-color: aliceblue;
            box-shadow: 0px 0px 8px gray;
            border-radius: 16px;
            width: 60%;
            height: 80%;
            min-height: 60px;
            min-width: 80px;
        }
    </style>
</head>
<body style="display:flex; flex-direction:column;">
    <head>
        <center>
            <h1 style="font-size: 2rem; padding: 8px 0;">
                SMART HOME
            </h1>
        </center>
    </head>
    <div class="body" style="flex-grow: 1; width:100%; height:100%;display:flex;">
        <div id="template">

            <div class="template_header_1">
                <h3 style="height: 100%; width:100%;">
                    <center style="height: 100%; line-height:var(--row); font-size: 1.4rem;">
                        Ngoài nhà
                    </center>
                </h3>
            </div>
            <div class="template_content_1">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Cửa ra vào
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <span>
                            Trạng thái:
                        </span>
                        <span id="state_door">
                            Đóng
                        </span>
                        <br/>
                        <span>
                            Cảnh báo:
                        </span>
                        <span id="warming_door">
                            An toàn
                        </span>
                        <br/>
                        <div id="close_door" class="btn">
                            Đóng cửa
                        </div>
                        <div id="open_door" class="btn">
                            Mở cửa
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_2">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Đèn công viên
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <div>
                            <span>
                                Đèn 1:
                            </span>
                            <span id="state_light_1">
                                ON
                            </span>
                            <span>
                                | Nhấn:
                            </span>
                            <div id="control_light_1" style="display: inline-block;" class="btn">
                                OFF
                            </div>
                        </div>
                        <div>
                            <span>
                                Đèn 2:
                            </span>
                            <span id="state_light_2">
                                ON
                            </span>
                            <span>
                                | Nhấn:
                            </span>
                            <div id="control_light_2" style="display: inline-block;" class="btn">
                                OFF
                            </div>
                        </div>
                        <div>
                            <span>
                                Đèn 3:
                            </span>
                            <span id="state_light_3">
                                ON
                            </span>
                            <span>
                                | Nhấn:
                            </span>
                            <div id="control_light_3" style="display: inline-block;" class="btn">
                                OFF
                            </div>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_3">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Nhiệt độ & Độ ẩm
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <div class="box_weather">
                            <center style="display: flex; flex-direction:column">
                                <span>
                                    Nhiệt độ
                                    <br/>
                                    <div class="box_weather_content" style="display: inline;" id="temperature">26</div>
                                    <span>oC</span>
                                    <br/>
                                </span>
                                <div style="height: 8px;"></div>
                                <span>
                                    Độ ẩm
                                    <br/>
                                    <div class="box_weather_content" style="display: inline;" id="humidity">80</div>
                                    <span>%</span>
                                    <br/>
                                </span>
                            </center>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_header_2">
                <h3 style="height: 100%; width:100%;">
                    <center style="height: 100%; line-height: var(--row); font-size: 1.4rem;">
                        Phòng khách
                    </center>
                </h3>
            </div>
            <div class="template_content_4">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Đèn
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <div>
                            <span>
                                Đèn:
                            </span>
                            <span id="state_light_livingroom">
                                ON
                            </span>
                            <span>
                                | Nhấn:
                            </span>
                            <div id="control_light_livingroom" style="display: inline-block;" class="btn">
                                OFF
                            </div>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_5">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Rèm cửa sổ
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <span>
                            Chế độ: 
                        </span>
                        <span id="state_mode_curtain_livingroom">
                            Auto
                        </span>
                        <br/>
                        <span>
                            Trạng thái:
                        </span>
                        <span id="state_curtain_livingroom">
                            OFF
                        </span>
                        <br/>
                        <span>
                            Nhấn:
                        </span>
                        <div id="control_curtain_livingroom" style="display: inline-block;" class="btn">
                            OFF
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_6">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Nhiệt độ
                    </center>
                </span>
                <div class="content_content">
                    <center style="flex-direction: column;">
                        <div>
                            <span id="temperature_livingroom">20</span>
                            <span style="width:4px"></span>
                            <span>oC</span>
                        </div>
                        <div>
                            <span> Quạt: </span>
                            <span id="state_fan_livingroom">OFF</span>
                            <span>| Nhấn:</span>
                            <div class="btn" id="control_fan_livingroom" style="display: inline-block;">ON</div>
                        </div>
                        <div>
                            <span> Máy lạnh: </span>
                            <span id="state_air-conditioner_livingroom">OFF</span>
                            <span>| Nhấn:</span>
                            <div class="btn" id="control_air-conditioner_livingroom" style="display: inline-block;">ON</div>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_header_3">
                <h3 style="height: 100%; width:100%;">
                    <center style="height: 100%; line-height: var(--row); font-size: 1.4rem;">
                        Phòng ngủ
                    </center>
                </h3>
            </div>
            <div class="template_content_7">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Đèn
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <div>
                            <span>
                                Đèn:
                            </span>
                            <span id="state_light_bedroom">
                                ON
                            </span>
                            <span>
                                | Nhấn:
                            </span>
                            <div id="control_light_bedroom" style="display: inline-block;" class="btn">
                                OFF
                            </div>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_8">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Rèm cửa sổ
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <span>
                            Chế độ: 
                        </span>
                        <span id="state_mode_curtain_bedroom">
                            Auto
                        </span>
                        <br/>
                        <span>
                            Trạng thái:
                        </span>
                        <span id="state_curtain_bedroom">
                            OFF
                        </span>
                        <br/>
                        <span>
                            Nhấn:
                        </span>
                        <div id="control_curtain_bedroom" style="display: inline-block;" class="btn">
                            OFF
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_9">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Nhiệt độ
                    </center>
                </span>
                <div class="content_content">
                    <center style="flex-direction: column;">
                        <div>
                            <span id="temperature_bedroom">20</span>
                            <span style="width:4px"></span>
                            <span>oC</span>
                        </div>
                        <div>
                            <span> Máy lạnh: </span>
                            <span id="state_air-conditioner_bedroom">OFF</span>
                            <span>| Nhấn:</span>
                            <div class="btn" id="control_air-conditioner_bedroom" style="display: inline-block;">ON</div>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_header_4">
                <h3 style="height: 100%; width:100%;">
                    <center style="height: 100%; line-height: var(--row); font-size: 1.4rem;">
                        Phòng ăn
                    </center>
                </h3>
            </div>
            <div class="template_content_10">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Đèn
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <div>
                            <span>
                                Đèn:
                            </span>
                            <span id="state_light_kitchen">
                                ON
                            </span>
                            <span>
                                | Nhấn:
                            </span>
                            <div id="control_light_kitchen" style="display: inline-block;" class="btn">
                                OFF
                            </div>
                        </div>
                    </center>
                </div>
            </div>
            <div class="template_content_11">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Quạt
                    </center>
                </span>
                <div class="content_content">
                    <center>
                        <span> Quạt: </span>
                        <span id="state_fan_kitchen">OFF</span>
                        <span>| Nhấn:</span>
                        <div class="btn" id="control_fan_kitchen" style="display: inline-block;">ON</div>
                    </center>
                </div>
            </div>
            <div class="template_content_12">
                <span class="content_title">
                    <center style="font-size: 20px; padding: 4px 0">
                        Nhiệt độ & Gas
                    </center>
                </span>
                <div class="content_content">
                    <center style="flex-direction: column;">
                        <div>
                            <span>Nhiệt độ: </span>
                            <span id="temperature_kitchen">20</span>
                            <span style="width:4px"></span>
                            <span>oC</span>
                        </div>
                        <div>
                            <span>Gas: </span>
                            <span id="gas_kitchen">40</span>
                            <span style="width:4px"></span>
                            <span>%</span>
                            <br/>
                            <span>
                                TT Quạt Gas:
                            </span>
                            <span id="state_gas_kitchen">OFF</span>
                        </div>
                    </center>
                </div>
            </div>
        </div>
    </div>
    <footer style="padding: 8px 0;">
        <center>
            <span style="text-decoration: underline; font-size: 1.2rem;">
                Design by: IAC
            </span
        </center>
    </footer>
    <script>
        const URL = "192.168.6.1/"
    </script>
</body>
</html>
)=====";