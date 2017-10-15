import React, {PureComponent} from 'react';


export default class reservation extends PureComponent{

    render(){
        return(
            <div id="block_reservation" className="col-md-8 well tabcontent">
                <h1 className="page-header">
                    <small>예약차단</small>
                </h1>
                <table className="table table-bordered" id="time_schedule">
                    <tr>
                      <th>오전수업</th>
                      <td>
                        <input className="time_field" name="class_am1" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="class_am2" type="text" value="" maxlength="2" required/> ~
                        <input className="time_field" name="class_am3" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="class_am4" type="text" value="" maxlength="2" required/>
                      </td>
                    </tr>
                    <tr>
                      <th>점심시간</th>
                      <td>
                        <input className="time_field" name="lunchtime1" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="lunchtime2" type="text" value="" maxlength="2" required/> ~
                        <input className="time_field" name="lunchtime3" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="lunchtime4" type="text" value="" maxlength="2" required/>
                      </td>
                    </tr>
                    <tr>
                      <th>오후수업</th>
                      <td>
                        <input className="time_field" name="class_pm1" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="class_pm2" type="text" value="" maxlength="2" required/> ~
                        <input className="time_field" name="class_pm3" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="class_pm4" type="text" value="" maxlength="2" required/>
                      </td>
                    </tr>
                    <tr>
                      <th>
                        방과후
                      </th>
                      <td>
                        <input className="time_field" name="afterschool1" type="text" value="" maxlength="2" required/>:
                        <input className="time_field" name="afterschool2" type="text" value="" maxlength="2" required/> ~
                      </td>
                    </tr>
                </table>
                <div className="col-md-12">
                  <input type=submit className="btn btn-default save_config" value="적용">
                </div>
            </div>
        );
    }
}
