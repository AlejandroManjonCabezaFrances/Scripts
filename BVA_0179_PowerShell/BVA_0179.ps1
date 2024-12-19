$archivoEntrada = "prueba 0179.txt"

# URL base de la API
$apiURL = "https://www.macvendorlookup.com/api/v2/"

$contenido = Get-Content $archivoEntrada -Raw

$macs = [regex]::Matches($contenido, 'MAC:<\/b>([\s\S]*?)<\/li>')
$lugares = [regex]::Matches($contenido, 'Lugar:<\/b>([\s\S]*?)<\/li>')
$fechas = [regex]::Matches($contenido, 'Fecha:<\/b>([\s\S]*?)<\/li>')

function consultar_API {
    param ($consultaMac)
    try {
            $response = Invoke-RestMethod -Uri "$apiURL$consultaMac" -Method Get
           
            # Extraer el campo 'company' de la respuesta JSON
            if ($response -and $response.company) {
                return $response.company
            } else {
                return "Fabricante no encontrado"
            }
        } catch {
            return "Error al consultar la API"
        }
}

function imprimir_bonito {
    param ($str, $palabra)

    if ($str -like "$palabra") {
        $antes, $despues, $p = $str -split "$palabra", 3
        Write-Host "$antes" -NoNewline
        Write-Host "$palabra" -ForegroundColor Green -NoNewline
        Write-Host "$despues" -ForegroundColor White
    } else {
        Write-Host "$str" -ForegroundColor Red
    }
}
for ($i = 0; $i -lt $macs.Count; $i++) {

    $currentMac = $($macs[$i].Groups[1].Value.Trim() -split ', ')
    $currentLugar = $($lugares[$i].Groups[1].Value.Trim() -split ', ')

    Write-Host "MACs: " -ForegroundColor Cyan
    foreach ($mac in $currentMac) {
        echo "$mac - $(consultar_API -consultaMac "$mac")"
    }

    Write-Host "Location:" -ForegroundColor Cyan
    foreach ($lugar in $currentLugar) {
        #echo "$lugar"
        imprimir_bonito -str "$lugar" -palabra "Ciudad BBVA"
    }
    Write-Host "Fecha: " -ForegroundColor Cyan

    echo "$($fechas[$i].Groups[1].Value.Trim())"

    echo "`n------------------------------------`n"
}
